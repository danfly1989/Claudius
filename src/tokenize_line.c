/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:12:44 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/29 12:12:52 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**last_check(char **tokens, t_dat *d)
{
	if (d->j < d->k)
	{
		tokens[d->j] = NULL;
		d->qtypes[d->j] = -1;
	}
	else
	{
		tokens[d->k] = NULL;
		d->qtypes[d->k] = -1;
	}
	return (tokens);
}

char	**ft_sub_tokenize_line(t_dat *d, char *str, int **quote_types_out)
{
	char	**tokens;

	if (!str)
		return (NULL);
	ft_reset_iterators(d);
	d->k = ft_count_tokens(str);
	if (d->k <= 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (d->k + 1));
	if (!tokens)
		return (NULL);
	d->qtypes = malloc(sizeof(int) * (d->k + 1));
	if (!d->qtypes)
	{
		free(tokens);
		return (NULL);
	}
	ft_bzero(d->qtypes, sizeof(int) * (d->k + 1));
	*quote_types_out = d->qtypes;
	return (tokens);
}

/*Second part of condition is to check if at start of string or not preceded by
backslash: handle as special (return 1). If neither condition met,
	block skipped and treated
as normal token (return 0)*/
int	handle_special_char(char **tokens, t_dat *d, char *str)
{
	if (is_special_char(str[d->i]) && (d->i == 0 || str[d->i - 1] != '\\'))
	{
		tokens[d->j] = ft_extract_special_token(str, d);
		if (!tokens[d->j])
			return (ft_free_token_quote(tokens, d->qtypes), -1);
		d->qtypes[d->j] = 0;
		d->j++;
		return (1);
	}
	return (0);
}

/*Inside the loop, the case of zero (normal token) will proceed with
neither if being triggered. The continue keyword is hit on 1 because
special char is found and no need for further processing. -1 is a legit
error case*/
char	**ft_tokenize_line(t_dat *d, char *str, int **quote_types_out)
{
	char	**tokens;
	int		result;

	tokens = ft_sub_tokenize_line(d, str, quote_types_out);
	if (!tokens)
		return (NULL);
	while (str[d->i] && d->j < d->k)
	{
		while (str[d->i] == ' ')
			d->i++;
		if (!str[d->i])
			break ;
		result = handle_special_char(tokens, d, str);
		if (result == -1)
			return (ft_free_token_quote(tokens, d->qtypes));
		if (result == 1)
			continue ;
		tokens[d->j] = ft_extract_token(str, d, &d->qtypes[d->j]);
		if (!tokens[d->j])
			return (ft_free_token_quote(tokens, d->qtypes));
		d->j++;
	}
	last_check(tokens, d);
	return (tokens);
}
