/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:57:17 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 10:57:27 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// The message should not be necessary on this one
// as the terminal will handle it
void	ft_nested_parent(t_dat *d, pid_t pid, int saved_stdin)
{
	int	status;
	int	signal_num;

	(void)d;
	status = 0;
	while (waitpid(pid, &status, 0) == -1 && errno == EINTR)
		;
	if (WIFEXITED(status))
		g_last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		signal_num = WTERMSIG(status);
		if (signal_num == SIGQUIT)
			g_last_exit_status = 131;
		else if (signal_num == SIGINT)
		{
			write(1, "\n", 1);
			g_last_exit_status = 130;
		}
	}
	if (dup2(saved_stdin, STDIN_FILENO) < 0)
		perror("dup2");
	close(saved_stdin);
}
