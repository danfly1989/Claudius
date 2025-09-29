/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:13:28 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/28 11:13:35 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_skip_quote(char *str, int i)
{
	char	quote;

	quote = str[i++];
	while (str[i] && str[i] != quote)
		i++;
	if (str[i])
		i++;
	return (i);
}

int	is_special_char(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == ';' || c == '&');
}

char	*ft_get_var_value(t_va *list, const char *name)
{
	size_t	n;

	n = ft_strlen(name);
	while (list)
	{
		if (list->name && ft_strlen(list->name) == n && ft_strncmp(list->name,
				name, n) == 0)
			return (list->value);
		list = list->next;
	}
	return (NULL);
}
