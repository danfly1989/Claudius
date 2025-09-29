/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:52:50 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/28 11:59:10 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strip_quotes_after_equal(char *s)
{
	char	*eq;
	char	quote;
	size_t	j;
	size_t	len;

	eq = ft_strchr(s, '=');
	len = ft_strlen(s);
	if (eq && ((eq[1] == '"' && s[len - 1] != '"') 
			|| (eq[1] == '\'' && s[len - 1] != '\'')))
		return ;
	if (eq && ((eq[1] == '"' && s[len - 1] == '"') 
			|| (eq[1] == '\'' && s[len - 1] == '\'')))
	{
		quote = eq[1];
		j = 0;
		while (eq[2 + j] && eq[2 + j] != quote)
		{
			eq[1 + j] = eq[2 + j];
			j++;
		}
		eq[1 + j] = '\0';
	}
}
