/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:06:45 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 20:07:03 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_pipe_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	return (0);
}

int	ft_create_pipes(int **fd, int tot)
{
	int	i;

	i = 0;
	while (i < tot - 1)
	{
		if (pipe(fd[i]) == -1)
		{
			perror("pipe");
			while (i-- > 0)
				free(fd[i]);
			free(fd);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_close_pipes(int **fd, int tot)
{
	int	i;

	i = 0;
	while (i < tot - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

int	ft_check_pipe(char **tokens, int i)
{
	if (i == 0 || !tokens[i + 1] || ft_is_redirection(tokens[i + 1]))
		return (ft_syntax_error(tokens[i + 1]));
	return (1);
}
