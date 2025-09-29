/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* exec.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/09/16 12:14:06 by daflynn           #+#    #+#             */
/* Updated: 2025/09/16 12:14:14 by daflynn          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_pipeline(t_dat *d, char ***cmd)
{
	int	**fd;

	pid_t *pids; // NEW: Pointer to store PIDs
	if (ft_strcmp(cmd[0][0], "./minishell") == 0)
	{
		ft_nested_minishell(d, cmd[0], NULL);
		return ;
	}
	// NEW: Allocate space for PIDs array
	pids = (pid_t *)malloc(sizeof(pid_t) * d->tot);
	if (!pids)
	{
		perror("malloc");
		return ;
	}
	fd = init_fd_array(d->tot);
	if (!fd || !ft_create_pipes(fd, d->tot))
	{
		if (fd)
			ft_free_fd(fd);
		free(pids); // NEW: Free PIDs on error
		return ;
	}
	// MODIFIED: Pass pids array to ft_fork_children
	ft_fork_children(d, cmd, fd, pids);
	ft_close_pipes(fd, d->tot);
	// MODIFIED: Pass pids array to ft_wait_children
	ft_wait_children(d->tot, pids);
	ft_set_main_signals();
	ft_free_fd(fd);
	free(pids); // NEW: Free PIDs array
}

/*Static to remind that this is a split from
exec command*/
static void	ft_execve_error(char *cmd)
// ... (ft_execve_error is unchanged)
{
	int	code;

	if (errno == EACCES || errno == EISDIR)
		code = 126;
	else if (errno == ENOENT)
		code = 127;
	else
		code = 1;
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(code);
}

void	ft_exec_command(t_dat *d, char **cmd)
{
	char	*cmd_path;

	if (!cmd || !cmd[0] || !*cmd[0])
		exit(127);
	/* SUGGESTION FOR TEST 56 (export | env):
		Ensure that ALL builtins (including 'export' and 'unset') are
		checked here to prevent 'ft_get_cmd_path' from failing with
		"command not found" (127). The check ft_is_pipe_builtin should
		probably be ft_is_builtin, or the logic needs to be extended.
		If 'ft_is_pipe_builtin' currently only covers builtins that pipe,
		Test 56 will still fail here because 'export' will fall through
		to ft_get_cmd_path.
	*/
	if (ft_is_pipe_builtin(cmd[0]))
		// <--- Re-evaluate this function's scope for ALL builtins
	{
		ft_execute_builtin_in_child(d, cmd);
		exit(g_last_exit_status);
	}
	cmd_path = ft_get_cmd_path(d, cmd[0], 0);
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
	execve(cmd_path, cmd, d->evs);
	free(cmd_path);
	ft_execve_error(cmd[0]);
}

void	ft_external_functions(t_dat *data, char *line)
// ... (ft_external_functions is unchanged in this context)
{
	char ***cmd;

	(void)line;
	if (!data || !data->xln || !data->xln[0])
		return ;
	if (!ft_validate_syntax(data->xln))
		return ;
	ft_list_to_env_array(data);
	data->no_pipes = ft_count_pipes(data->xln);
	if (!data->no_pipes && !ft_count_redirections(data->xln))
	{
		if (ft_all_valid_lvar(data, data->xln))
			ft_update_local_variables(data);
		if (ft_handle_builtin(data, data->st))
			return ;
	}
	cmd = ft_parse_cmd(data, 0, 0, 0);
	if (!cmd)
		return ;
	ft_execute_pipeline(data, cmd);
	ft_clean_cmd(cmd);
	ft_free_string_array(data->evs);
	data->evs = NULL;
}