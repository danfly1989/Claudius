/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:23:04 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:23:11 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_valid_var(char *str)
{
	size_t	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] != '=')
		return (0);
	return (1);
}

t_va	*ft_find_var(t_va *list, const char *name)
{
	while (list)
	{
		if (list->name && ft_strncmp(list->name, name, ft_strlen(name)) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int	ft_update_var_value(t_va *node, const char *value)
{
	char	*new_value;

	new_value = ft_strdup(value);
	if (!new_value)
		return (0);
	free(node->value);
	node->value = new_value;
	return (1);
}

int	ft_add_local_var(t_dat *data, char *str)
{
	t_va	*new_node;
	t_va	*last;

	new_node = ft_create_var_node(str);
	if (!new_node)
		return (0);
	if (!data->lo)
	{
		data->lo = new_node;
		return (1);
	}
	last = data->lo;
	while (last->next)
		last = last->next;
	last->next = new_node;
	return (1);
}

int	ft_all_valid_lvar(t_dat *data, char **arr)
{
	int	i;

	if (!arr)
		return (0);
	ft_reset_iterators(data);
	i = 0;
	while (arr[i])
		i++;
	data->tot = i;
	i = 0;
	while (arr[i])
	{
		if (!ft_valid_var(arr[i]))
		{
			data->st = i;
			return (0);
		}
		i++;
	}
	return (1);
}
