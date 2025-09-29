/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:06:42 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:06:49 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_lines(t_dat *data)
{
	ft_free_string_array(data->ln);
	data->ln = NULL;
	ft_free_string_array(data->xln);
	data->xln = NULL;
}

void	ft_free_string_array(char **str_array)
{
	int	i;

	if (str_array == NULL)
		return ;
	i = 0;
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		str_array[i] = NULL;
		i++;
	}
	free(str_array);
}

void	ft_free_list(t_va *head)
{
	t_va	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

void	ft_free_redirection(t_rdr *r)
{
	if (r->in_file)
	{
		free(r->in_file);
		r->in_file = NULL;
	}
	if (r->out_file)
	{
		free(r->out_file);
		r->out_file = NULL;
	}
	if (r->append_file)
	{
		free(r->append_file);
		r->append_file = NULL;
	}
	if (r->heredoc_delim)
	{
		free(r->heredoc_delim);
		r->heredoc_delim = NULL;
	}
}

char	**ft_free_token_quote(char **tokens, int *quote_types)
{
	if (tokens)
		free(tokens);
	if (quote_types)
		free(quote_types);
	return (NULL);
}
