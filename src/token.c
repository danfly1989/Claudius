/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:28:57 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 19:29:04 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Tokenization needed to be modified in order to make
the > and < operators work correctly without spacing. The
is_special_character was also created for this purpose.
Additional count.c needed to be modified to accurately count
tokens after these changes.
*/
char	*ft_extract_special_token(char *str, t_dat *d)
{
	char	*token;
	int		len;

	if (str[d->i] == '>' && str[d->i + 1] == '>')
	{
		len = 2;
		token = malloc(3);
		ft_strlcpy(token, &str[d->i], 3);
	}
	else if (str[d->i] == '<' && str[d->i + 1] == '<')
	{
		len = 2;
		token = malloc(3);
		ft_strlcpy(token, &str[d->i], 3);
	}
	else
	{
		len = 1;
		token = malloc(2);
		token[0] = str[d->i];
		token[1] = '\0';
	}
	d->i += len;
	return (token);
}

int	ft_skip_token(char *str, int i)
{
	int		in_quotes;
	char	quote_char;

	in_quotes = 0;
	quote_char = 0;
	while (str[i] && (in_quotes || (str[i] != ' ' && !is_special_char(str[i]))))
	{
		if (!in_quotes && (str[i] == '\'' || str[i] == '"'))
		{
			in_quotes = 1;
			quote_char = str[i];
		}
		else if (in_quotes && str[i] == quote_char)
		{
			in_quotes = 0;
		}
		i++;
	}
	return (i);
}

char	*ft_strjoin_char(const char *s, char c)
{
	char	*new;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}
