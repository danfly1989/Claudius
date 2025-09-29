/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:02:31 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:02:38 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_increment_shlvl(t_va **env_list)
{
	t_va	*node;
	char	*lvl_str;
	int		level;

	node = *env_list;
	while (node)
	{
		if (ft_strcmp(node->name, "SHLVL") == 0)
		{
			level = ft_atoi(node->value) + 1;
			if (level < 1)
				level = 1;
			lvl_str = ft_itoa(level);
			if (!lvl_str)
				lvl_str = ft_strdup("1");
			free(node->value);
			node->value = lvl_str;
			return ;
		}
		node = node->next;
	}
	ft_create_shlvl(env_list);
}

int	ft_create_shlvl(t_va **env_list)
{
	t_va	*new_node;

	new_node = malloc(sizeof(t_va));
	if (!new_node)
		return (0);
	new_node->name = ft_strdup("SHLVL");
	new_node->value = ft_itoa(1);
	if (!new_node->name || !new_node->value)
	{
		free(new_node->name);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = *env_list;
	*env_list = new_node;
	return (1);
}

void	ft_nested_minishell(t_dat *d, char **cmd, char *cmd_path)
{
	pid_t	pid;
	int		saved_stdin;

	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdin < 0)
	{
		perror("dup");
		return ;
	}
	ft_set_main_nested_signals();
	pid = fork();
	if (pid == 0)
		ft_nested_child(d, cmd, cmd_path, saved_stdin);
	else if (pid > 0)
		ft_nested_parent(d, pid, saved_stdin);
	else
		perror("nesting minishell fork");
	ft_set_main_signals();
}
