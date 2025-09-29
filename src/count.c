/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:28:19 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:28:25 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_tokens(char *str)
{
	int	count;
	int	i;
	int	in_quotes;

	count = 0;
	i = 0;
	in_quotes = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		count++;
		if (is_special_char(str[i]) && (i == 0 || str[i - 1] != '\\'))
		{
			if (str[i] == '>' && str[i + 1] == '>')
				i += 2;
			else
				i += 1;
			continue ;
		}
		i = ft_skip_token(str, i);
	}
	return (count);
}

int	ft_count_list(t_va *head)
{
	t_va	*cur;
	int		count;

	cur = head;
	count = 0;
	while (cur)
	{
		if (cur->name)
			count++;
		cur = cur->next;
	}
	return (count);
}

int	ft_count_pipes(char **tokens)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "|") == 0)
			count++;
		i++;
	}
	return (count);
}

int	ft_count_redirections(char **tokens)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (ft_is_redirection(tokens[i]))
			count++;
		i++;
	}
	return (count);
}
