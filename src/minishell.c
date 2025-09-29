/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagwu <dagwu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:44:41 by dagwu             #+#    #+#             */
/*   Updated: 2025/06/14 18:44:46 by dagwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_empty_str(char **arr)
{
	size_t	i;
	size_t	k;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '\0')
		{
			free(arr[i]);
			arr[i] = NULL;
			k = i;
			while (arr[k + 1])
			{
				arr[i] = arr[k + 1];
				arr[k + 1] = NULL;
				k++;
			}
			i++;
		}
		else
			i++;
	}
}

void	ft_export_error(char *arg, char *message)
{
	write(2, "export: '", 9);
	write(2, arg, ft_strlen(arg));
	write(2, "': ", 3);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	g_last_exit_status = 1;
}

void	ft_check_var_assign_and_expand_line_ext(t_dat *data, char *line)
{
	ft_strip_quotes_from_xln(data);
	ft_remove_empty_str(data->xln);
	ft_external_functions(data, line);
	if (data->qtypes)
	{
		free(data->qtypes);
		data->qtypes = NULL;
	}
	ft_free_string_array(data->ln);
	data->ln = NULL;
	ft_free_string_array(data->xln);
	data->xln = NULL;
}

void	ft_check_var_assign_and_expand_line(t_dat *data, char *line)
{
	if (!data || !line)
		return ;
	data->qtypes = NULL;
	data->ln = ft_tokenize_line(data, line, &data->qtypes);
	if (!data->ln)
	{
		if (data->qtypes)
			free(data->qtypes);
		return ;
	}
	data->xln = ft_expand_tokens(data, data->ln, data->qtypes, 0);
	if (!data->xln)
	{
		if (data->qtypes)
			free(data->qtypes);
		ft_free_string_array(data->ln);
		data->ln = NULL;
		return ;
	}
	ft_check_var_assign_and_expand_line_ext(data, line);
}
