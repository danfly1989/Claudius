/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:02:33 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 20:02:39 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*All functions in this file are formerly part of a much larger
apply_redirect function, which was split further down. All functions here
are helpers for processing redirection tokens, which is in turn a helper
 Each one returns a value (0) on failure
and 1 on success as they are used in if conditional within that
function*/

int	handle_infile(char **tokens, int *i, int *last_in_fd)
{
	if (*last_in_fd != -1)
		close(*last_in_fd);
	*last_in_fd = open(tokens[*i + 1], O_RDONLY);
	if (*last_in_fd < 0)
	{
		perror(tokens[*i + 1]);
		return (0);
	}
	*i += 2;
	return (1);
}

int	ft_redir_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "minishell: %s: No such file or directory\n", file);
		return (0);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2 in");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	handle_outfile_trunc(char **tokens, int *i, int *last_out_fd)
{
	if (*last_out_fd != -1)
		close(*last_out_fd);
	*last_out_fd = open(tokens[*i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*last_out_fd < 0)
	{
		perror(tokens[*i + 1]);
		return (0);
	}
	*i += 2;
	return (1);
}

int	handle_outfile_append(char **tokens, int *i, int *last_out_fd)
{
	if (*last_out_fd != -1)
		close(*last_out_fd);
	*last_out_fd = open(tokens[*i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (*last_out_fd < 0)
	{
		perror(tokens[*i + 1]);
		return (0);
	}
	*i += 2;
	return (1);
}

int	handle_heredoc_redirect(char *heredoc_delim)
{
	int	fd;

	if (!heredoc_delim)
		return (1);
	fd = handle_heredoc(heredoc_delim);
	if (fd == -1)
		return (0);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
