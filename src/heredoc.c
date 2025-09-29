/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:58:57 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/12 19:58:59 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_heredoc_content(int fd, const char *delimiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			write(STDOUT_FILENO, "\n", 1);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

void	heredoc_child(int pipe_fd[2], const char *delimiter)
{
	struct sigaction	sa;

	close(pipe_fd[0]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
	sa.sa_handler = heredoc_child_sigint;
	sigaction(SIGINT, &sa, NULL);
	read_heredoc_content(pipe_fd[1], delimiter);
	close(pipe_fd[1]);
	exit(0);
}

int	heredoc_parent(pid_t pid, int pipe_fd[2])
{
	int	status;

	close(pipe_fd[1]);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		close(pipe_fd[0]);
		return (-1);
	}
	return (pipe_fd[0]);
}

int	handle_heredoc(const char *delimiter)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (-1);
	}
	if (pid == 0)
		heredoc_child(pipe_fd, delimiter);
	return (heredoc_parent(pid, pipe_fd));
}

void	heredoc_child_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	exit(130);
}
