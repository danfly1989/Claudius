/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:32:13 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 19:32:20 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_update_existing_var(t_va *node, const char *name, const char *val)
{
	while (node)
	{
		if (ft_strncmp(node->name, name, ft_strlen(name)) == 0)
		{
			free(node->value);
			node->value = ft_strdup(val);
			if (!node->value)
				perror("minishell: malloc error");
			return (1);
		}
		node = node->next;
	}
	return (0);
}

void	ft_echo(char **arr, size_t k)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (arr[k + i] != NULL && ft_strncmp(arr[k + i], "-n", 2) == 0)
	{
		newline = 0;
		i++;
	}
	while (arr[k + i] != NULL)
	{
		printf("%s", arr[k + i]);
		i++;
		if (arr[k + i] != NULL)
			printf(" ");
	}
	if (newline)
		printf("\n");
}

int	ft_var_name_only(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_update_local_variables(t_dat *d)
{
	int		i;
	char	*name;
	t_va	*node;

	if (!d || !d->xln)
		return ;
	i = 0;
	while (d->xln[i])
	{
		name = ft_extract_var_name(d->xln[i]);
		if (!name)
			return ;
		node = ft_find_var(d->lo, name);
		if (node)
			ft_update_var_value(node, ft_strchr(d->xln[i], '=') + 1);
		else
			ft_add_local_var(d, d->xln[i]);
		free(name);
		i++;
	}
}
