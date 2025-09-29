/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:36:50 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 19:36:56 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_builtin(t_dat *data, size_t k)
{
	if (data == NULL || data->xln == NULL)
		return (0);
	if (ft_strcmp(data->xln[k], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(data->xln[k], "cd") == 0)
		ft_change_directory(data, k);
	else if (ft_strcmp(data->xln[k], "echo") == 0)
		ft_echo(data->xln, k);
	else if (ft_strcmp(data->xln[k], "exit") == 0)
		ft_exit(data, k);
	else if (ft_strcmp(data->xln[k], "env") == 0)
		ft_env(data);
	else if (ft_strcmp(data->xln[k], "unset") == 0)
		ft_unset_multi_var(data, k);
	else if (ft_strcmp(data->xln[k], "export") == 0)
		ft_export_multi_var(data, k);
	else
		return (0);
	return (1);
}

void	ft_free_fd(int **fd)
{
	int	i;

	if (!fd)
		return ;
	i = 0;
	while (fd[i])
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

int	ft_is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	return (0);
}

void	ft_execute_builtin_in_child(t_dat *d, char **cmd)
{
	if (!ft_strcmp(cmd[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, 0);
	else if (!ft_strcmp(cmd[0], "env"))
		ft_env(d);
}
