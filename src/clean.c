/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:07:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 12:07:44 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cleanup_data(t_dat *data)
{
	if (data->ev)
		ft_free_list(data->ev);
	if (data->av)
		ft_free_list(data->av);
	if (data->lo)
		ft_free_list(data->lo);
	if (data->ln)
		ft_free_string_array(data->ln);
	if (data->xln)
		ft_free_string_array(data->xln);
	if (data->tmp1)
		free(data->tmp1);
	if (data->tmp2)
		free(data->tmp2);
	if (data->qtypes)
		free(data->qtypes);
	if (data->evs)
		ft_free_string_array(data->evs);
	if (data->avs)
		ft_free_string_array(data->avs);
	ft_nullify_pointers(data);
}

char	***ft_clean_cmd(char ***cmd)
{
	int	i;

	if (!cmd)
		return (NULL);
	i = 0;
	while (cmd[i])
	{
		ft_free_string_array(cmd[i]);
		i++;
	}
	free(cmd);
	return (NULL);
}

void	ft_cleanup_exit(t_dat *data, int flag)
{
	ft_cleanup_data(data);
	rl_clear_history();
	exit(flag);
}
