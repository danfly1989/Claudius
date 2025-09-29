/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:05:09 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 20:05:15 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_exit_status(char *res, int status, int *i)
{
	char	*temp;

	temp = ft_itoa(status);
	res = ft_strjoin_free(res, temp);
	free(temp);
	*i += 2;
	return (res);
}

void	ft_exit_numeric_error(char *arg)
{
	write(2, "minishell: exit: ", 18);
	write(2, arg, ft_strlen(arg));
	write(2, ": numeric argument required\n", 29);
}

void	ft_exit(t_dat *data, size_t k)
{
	int	status;

	if (data->xln[k + 1] && data->xln[k + 2])
	{
		g_last_exit_status = 1;
		write(2, "minishell: exit: too many arguments\n", 36);
		return ;
	}
	rl_clear_history();
	if (data->xln[k + 1] == NULL)
		ft_cleanup_exit(data, 0);
	if (ft_is_number(data->xln[k + 1]) == 0)
	{
		ft_exit_numeric_error(data->xln[k + 1]);
		ft_cleanup_exit(data, 2);
	}
	status = ft_atoi(data->xln[k + 1]);
	ft_cleanup_exit(data, status % 256);
}

char	*ft_expand_exit_status(t_dat *d, char *token)
{
	char	*res;
	int		i;

	(void)d;
	i = 0;
	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] == '?')
			res = append_exit_status(res, g_last_exit_status, &i);
		else
			res = append_char(res, token, &i);
	}
	return (res);
}
