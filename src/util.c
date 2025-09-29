/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:33:47 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 16:33:57 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_nullify_pointers(t_dat *data)
{
	data->ev = NULL;
	data->av = NULL;
	data->lo = NULL;
	data->ln = NULL;
	data->xln = NULL;
	data->tmp1 = NULL;
	data->tmp2 = NULL;
	data->qtypes = NULL;
	data->evs = NULL;
	data->avs = NULL;
}

t_va	*create_lst_frm_arr(char **arr, t_va *h, int i, t_va *(*f)(char *))
{
	t_va	*current;
	t_va	*new_node;

	current = NULL;
	while (arr[i])
	{
		new_node = f(arr[i]);
		if (!new_node)
		{
			if (h)
				ft_free_list(h);
			return (NULL);
		}
		if (h == NULL)
			h = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	return (h);
}

void	ft_reset_iterators(t_dat *data)
{
	data->i = 0;
	data->j = 0;
	data->k = 0;
	data->tot = 0;
	data->st = 0;
}

void	ft_setup_io(int **fd, size_t i, size_t total)
{
	if (i > 0)
		dup2(fd[i - 1][0], STDIN_FILENO);
	if (i < total - 1)
		dup2(fd[i][1], STDOUT_FILENO);
}

int	**init_fd_array(int tot)
{
	int	**fd;
	int	i;

	fd = malloc(sizeof(int *) * tot);
	if (!fd)
		return (NULL);
	i = 0;
	while (i < tot - 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
		{
			while (--i >= 0)
				free(fd[i]);
			free(fd);
			return (NULL);
		}
		i++;
	}
	fd[tot - 1] = NULL;
	return (fd);
}
