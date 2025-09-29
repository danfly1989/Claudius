/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:29:54 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:30:01 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_token(char *str, t_dat *d, int *quote_type)
{
	int		start;
	int		end;
	char	*token;

	start = d->i;
	*quote_type = 0;
	end = ft_get_token_end(str, d->i);
	d->i = end;
	token = ft_strndup(str + start, end - start);
	if (!token)
		return (NULL);
	ft_detect_quote_type(token, quote_type);
	return (token);
}

int	ft_get_token_end(char *str, int i)
{
	if (str[i] == '\'' || str[i] == '"')
		return (ft_skip_quote(str, i));
	return (ft_skip_token(str, i));
}

char	*ft_extract_var_key(const char *str, size_t *i)
{
	size_t	start;
	char	*key;

	start = *i;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_strdup("?"));
	}
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	key = ft_substr(str, start, *i - start);
	return (key);
}

char	*ft_get_val_from_list(t_va *head, const char *key)
{
	t_va	*cur;
	size_t	len;

	if (!head || !key)
		return (NULL);
	len = ft_strlen(key);
	cur = head;
	while (cur)
	{
		if (ft_strncmp(cur->name, key, len + 1) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

char	**ft_extract_tokens(t_dat *data, int start, int end)
{
	char	**tokens;
	int		i;

	tokens = malloc((end - start + 1) * sizeof(char *));
	if (!tokens)
		return (NULL);
	i = 0;
	while (start < end)
	{
		tokens[i] = ft_strdup(data->xln[start]);
		if (!tokens[i])
		{
			ft_free_string_array(tokens);
			return (NULL);
		}
		start++;
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
