/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:12:32 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:12:38 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_redir(char **tokens, int i)
{
	if (!tokens[i + 1] || ft_is_redirection(tokens[i + 1])
		|| !ft_strcmp(tokens[i + 1], "|"))
		return (ft_syntax_error(tokens[i + 1]));
	return (1);
}

int	ft_is_redirection(char *str)
{
	return (!ft_strcmp(str, "<") || !ft_strcmp(str, ">") || !ft_strcmp(str,
			">>") || !ft_strcmp(str, "<<"));
}

int	ft_is_number(const char *str)
{
	size_t	i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_interactive(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}

int	ft_strisspace(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
