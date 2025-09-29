/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:11:37 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/28 09:11:40 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*These functions emulate bash as far as output is concerned but follow
different logic. Instead of POSIX Open, dup2, close, repeat, write,
the pattern we use here is open close if not last fd,
then dup2 and write if last_fd.
Meaning the behaviour of writing to the final file is the same
as far as output is concerned.*/

static int	apply_input_redirect(int last_in_fd)
{
	if (last_in_fd == -1)
		return (1);
	if (dup2(last_in_fd, STDIN_FILENO) < 0)
	{
		perror("dup2 stdin");
		close(last_in_fd);
		return (0);
	}
	close(last_in_fd);
	return (1);
}

static int	apply_output_redirect(int last_out_fd)
{
	if (last_out_fd == -1)
		return (1);
	if (dup2(last_out_fd, STDOUT_FILENO) < 0)
	{
		perror("dup2 stdout");
		close(last_out_fd);
		return (0);
	}
	close(last_out_fd);
	return (1);
}

/*The helper functions (i.e.) the handlers called within this function
are all in hande_redir.c.
KEEP ORIGINAL LOGIC - The issue is elsewhere*/
static int	process_redirection_tokens(char **tokens, int *last_in_fd,
		int *last_out_fd)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "<") == 0 && tokens[i + 1])
		{
			if (!handle_infile(tokens, &i, last_in_fd))
				return (0);
		}
		else if (ft_strcmp(tokens[i], ">") == 0 && tokens[i + 1])
		{
			if (!handle_outfile_trunc(tokens, &i, last_out_fd))
				return (0);
		}
		else if (ft_strcmp(tokens[i], ">>") == 0 && tokens[i + 1])
		{
			if (!handle_outfile_append(tokens, &i, last_out_fd))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

/*This is the primary function to look at for any redirection
It is the launch pad so to speak. Each helper called inside an if
returns 0 on failure and 1 on success. NOT 1 resolves to false, so
we. Negation means failures activate instant return. If on redirect
fails do not attempt the rest

REVERT TO ORIGINAL - The real issues are:
1. Quote processing in filenames (test 87)
2. Pipeline exit code handling in exec.c (tests 96, 126, 127)
3. Empty variable expansion (test 134)
*/
int	ft_apply_redirections(t_rdr *r, char **tokens)
{
	int last_in_fd;
	int last_out_fd;

	last_in_fd = -1;
	last_out_fd = -1;
	if (!handle_heredoc_redirect(r->heredoc_delim))
		return (0);
	if (!process_redirection_tokens(tokens, &last_in_fd, &last_out_fd))
		return (0);
	if (!apply_input_redirect(last_in_fd))
		return (0);
	if (!apply_output_redirect(last_out_fd))
		return (0);
	return (ft_remove_redirections(&tokens, 0, 0));
}