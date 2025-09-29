/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:56:15 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 19:56:21 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_appropriate_child_signal(char *str)
{
	if (ft_is_builtin(str) && ft_is_pipe_builtin(str))
		ft_set_main_signals();
	else
		ft_set_child_signals();
}

void	ft_child_process(t_dat *d, char ***cmd, int **fd, size_t i)
{
	t_rdr	r;
	int		len;

	if (!cmd || !cmd[i] || !cmd[i][0])
		exit(1);
	len = 0;
	while (cmd[i][len])
		len++;
	ft_memset(&r, 0, sizeof(r));
	if (!ft_validate_segment(cmd[i], 0, len))
		exit(1);
	ft_setup_io(fd, i, d->tot);
	ft_close_pipes(fd, d->tot);
	ft_appropriate_child_signal(cmd[i][0]);
	ft_parse_redirection(cmd[i], &r);
	if (!ft_apply_redirections(&r, cmd[i]))
	{
		ft_free_redirection(&r);
		exit(1);
	}
	ft_exec_command(d, cmd[i]);
}

// Original:
// void    ft_fork_children(t_dat *d, char ***cmd, int **fd)

// Modified: Add pid_t *pids parameter
void	ft_fork_children(t_dat *d, char ***cmd, int **fd, pid_t *pids)
{
	pid_t	pid;
	size_t	i;

	i = 0;
	while (i < d->tot)
	{
		if (!cmd[i] || !cmd[i][0])
		{
			// If command is empty,
				// or handle the wait count adjustment outside. For now,
				// let's stick to the commands that are actually forked.
				if (pids) pids[i] = -1; // Indicate no process for this segment
			i++;
			continue ;
		}
		pid = fork();
		if (pid == 0)
		{
			ft_set_child_signals();
			ft_child_process(d, cmd, fd, i);
		}
		else if (pid < 0)
		{
			perror("fork");
			if (pids)
				pids[i] = -1;
		}
		else // pid > 0 (Parent)
		{
			if (pids)
				pids[i] = pid; // <-- STORE THE PID
		}
		i++;
	}
}

void	ft_nested_child(t_dat *d, char **cmd, char *cmd_path, int s_stdin)
{
	close(s_stdin);
	cmd_path = ft_get_cmd_path(d, cmd[0], 0);
	if (!cmd_path)
	{
		ft_cmd_not_found(cmd[0]);
		exit(1);
	}
	execve(cmd_path, cmd, d->evs);
	exit(1);
}

// Original:
// void    ft_wait_children(int tot)

// Modified: Add pid_t *pids parameter
void	ft_wait_children(int tot, pid_t *pids)
{
	int status;
	int i;
	int signal_num;
	int last_exit_code;
	pid_t waited_pid;

	last_exit_code = 0;
	i = 0;
	// Iterate through all forked PIDs
	while (i < tot)
	{
		signal(SIGINT, SIG_IGN);
		// Wait for the specific child process PID[i]
		// If pids[i] is -1 (from ft_fork_children), this wait will likely fail,
		// but we only care about the last command's status.
		if (pids[i] != -1)
			waited_pid = waitpid(pids[i], &status, 0);
		else
		{
			i++;
			continue ;
		}

		// This block should only update last_exit_code if it's the
		// last successfully forked command's exit code.
		// The simplest way to comply with Bash is to track *every* exit code,
		// but *only* use the one from the last process as the final status.

		if (waited_pid > 0)
		{
			if (WIFSIGNALED(status))
			{
				signal_num = WTERMSIG(status);
				if (signal_num == SIGQUIT)
					(printf("quit: core dumped\n"), last_exit_code = 131);
				else if (signal_num == SIGINT)
					(write(1, "\n", 1), last_exit_code = 130);
			}
			else if (WIFEXITED(status))
				last_exit_code = WEXITSTATUS(status);
		}
		i++;
	}

	// Now, we need to ensure that the exit code of the last *valid* command
	// is set. Since we wait for PIDs in order (1st cmd, 2nd cmd, ...,
	// the value of `last_exit_code` at the end of the loop *should* be the
	// status of the last command that ran.

	// For the specific failure cases (96, 126, 127) where the first command
	// fails but the last one *runs* and exits with 0, this structure should
	// now correctly capture the last command's status.

	ft_set_main_signals();
	g_last_exit_status = last_exit_code;
}