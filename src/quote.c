/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:25:14 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 13:18:06 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_copy_unquoted_segment(char *str, size_t len, char *ret,
		t_dat *data)
{
	char	quote;
	size_t	start;
	size_t	end;

	quote = str[data->i];
	start = data->i + 1;
	end = start;
	while (end < len && str[end] != quote)
		end++;
	if (end < len && str[end] == quote)
	{
		while (start < end)
			ret[data->j++] = str[start++];
		data->i = end + 1;
	}
	else
		ret[data->j++] = str[data->i++];
}

void	ft_strip_within_str(t_dat data, char *str, size_t len)
{
	char	ret[256];

	data.i = 0;
	data.j = 0;
	while (data.i < len && str[data.i])
	{
		if (str[data.i] == '"' || str[data.i] == '\'')
			ft_copy_unquoted_segment(str, len, ret, &data);
		else
			ret[data.j++] = str[data.i++];
	}
	ret[data.j] = '\0';
	data.i = 0;
	while (data.i <= data.j)
	{
		str[data.i] = ret[data.i];
		data.i++;
	}
}

void	ft_strip_surrounding_quotes(char *s)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(s);
	if (len >= 2 && ((s[0] == '"' && s[len - 1] != '"') || (s[0] == '\''
				&& s[len - 1] != '\'')))
		return ;
	if (len >= 2 && ((s[0] == '"' && s[len - 1] == '"') || (s[0] == '\''
				&& s[len - 1] == '\'')))
	{
		j = 1;
		while (j < len - 1)
		{
			s[j - 1] = s[j];
			j++;
		}
		s[j - 1] = '\0';
	}
}

void	ft_strip_quotes_from_xln(t_dat *d)
{
	size_t	i;

	i = 0;
	if (!d || !d->xln)
		return ;
	while (d->xln[i])
	{
		if (d->xln[i])
		{
			ft_strip_surrounding_quotes(d->xln[i]);
			ft_strip_quotes_after_equal(d->xln[i]);
			ft_strip_within_str(*d, d->xln[i], ft_strlen(d->xln[i]));
		}
		i++;
	}
}

void	ft_detect_quote_type(char *token, int *quote_type)
{
	char	*eq;
	char	quote;

	if (token[0] == '\'')
		*quote_type = 1;
	else if (token[0] == '"')
		*quote_type = 2;
	else
	{
		eq = ft_strchr(token, '=');
		if (eq && (*(eq + 1) == '\'' || *(eq + 1) == '"'))
		{
			quote = *(eq + 1);
			if (quote == '\'')
				*quote_type = 1;
			else
				*quote_type = 2;
		}
	}
}
