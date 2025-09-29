/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:35:29 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:35:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_loop(char *token, t_dat *data, char **res, size_t *i)
{
	char	*key;
	char	*val;
	char	*tmp;

	key = ft_extract_var_key(token, i);
	if (!key)
		return ;
	val = NULL;
	if (data->lo != NULL)
		val = ft_get_var_value(data->lo, key);
	if (val == NULL)
		val = ft_get_var_value(data->ev, key);
	if (val != NULL)
	{
		tmp = *res;
		*res = ft_strjoin(*res, val);
		free(tmp);
	}
	free(key);
}

char	*ft_expand_token(char *token, t_dat *data, int qt, size_t i)
{
	char	*res;
	char	*tmp;

	if (qt == 1)
		return (ft_strdup(token));
	res = ft_calloc(1, sizeof(char));
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] && (ft_isalpha(token[i + 1])
				|| token[i + 1] == '_' || token[i + 1] == '?'))
		{
			i++;
			ft_expand_loop(token, data, &res, &i);
		}
		else
		{
			tmp = res;
			res = ft_strjoin_char(res, token[i++]);
			free(tmp);
		}
	}
	return (res);
}

void	*ft_free_error_expanded(char **expanded, int i)
{
	while (--i >= 0)
		free(expanded[i]);
	free(expanded);
	return (NULL);
}

static char	**ft_fill_expanded(t_dat d, char **tokens, int *qtypes,
		char **expanded)
{
	d.i = 0;
	d.j = 0;
	while (tokens[d.i])
	{
		if (qtypes[d.i] == 1)
		{
			expanded[d.j] = ft_strdup(tokens[d.i]);
			if (!expanded[d.j])
				return (ft_free_error_expanded(expanded, d.j));
			d.j++;
		}
		else
		{
			if (expanded[d.j] && expanded[d.j][0] == '\0' && qtypes[d.i] != 2)
			{
				free(expanded[d.j]);
				expanded[d.j] = NULL;
			}
			else
				d.j++;
		}
		d.i++;
	}
	expanded[d.j] = NULL;
	return (expanded);
}

char	**ft_expand_tokens(t_dat *d, char **tokens, int *qtypes, int i)
{
	char	**expanded;

	while (tokens[i])
		i++;
	expanded = malloc(sizeof(char *) * (i + 1));
	if (!expanded)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		if (qtypes[i] != 1)
		{
			d->tmp2 = ft_expand_exit_status(d, tokens[i]);
			expanded[i] = ft_expand_token(d->tmp2, d, qtypes[i], 0);
			free(d->tmp2);
			d->tmp2 = NULL;
		}
		i++;
	}
	return (ft_fill_expanded(*d, tokens, qtypes, expanded));
}
