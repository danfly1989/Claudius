/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:14:56 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:15:04 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Modified this file to return 2 on syntax errors. For validate
syntax, this was achieved by the call to ft_syntax_error_msg. I
am uncertain if the change of last_exit status was necessary in this
case, but I felt it safer and it doesn't break anything.Tests appear
much more sensitive to the direct return value in this context.*/

int	ft_syntax_error(char *token)
{
	char	*mes1;
	char	*mes2;

	mes1 = "minishell: syntax error near unexpected token `";
	mes2 = "minishell: syntax error near unexpected token `newline'\n";
	if (token)
	{
		write(2, mes1, ft_strlen(mes1));
		write(2, token, ft_strlen(token));
		write(2, "'\n", 2);
	}
	else
		write(2, mes2, ft_strlen(mes2));
	g_last_exit_status = 2;
	return (2);
}

int	ft_validate_syntax(char **tokens)
{
	int	i;

	if (!tokens || !tokens[0])
		return (1);
	if (ft_is_redirection(tokens[0]) && ft_strcmp(tokens[0], "<<"))
		return (ft_syntax_error_msg(tokens[0]));
	i = 0;
	while (tokens[i])
	{
		if (ft_is_redirection(tokens[i]))
		{
			if (!ft_check_redir(tokens, i))
				return (0);
		}
		else if (!ft_strcmp(tokens[i], "|"))
		{
			if (!ft_check_pipe(tokens, i))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_syntax_error_msg(char *token)
{
	char	*prefix;
	char	*newline;

	prefix = "minishell: syntax error near unexpected token `";
	newline = "'\n";
	if (token)
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, token, ft_strlen(token));
		write(2, newline, 2);
	}
	else
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, "newline", 7);
		write(2, newline, 2);
	}
	g_last_exit_status = 2;
	return (2);
}
