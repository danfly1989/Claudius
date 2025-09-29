/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:22:41 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/13 20:22:49 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*line;
	t_dat	data;

	data = ft_duplicate_input_args(argc, argv, env);
	ft_set_main_signals();
	while (1)
	{
		line = readline("dandav>");
		if (line == NULL)
		{
			if (ft_is_interactive())
				write(1, "exit\n", 5);
			break ;
		}
		if (line && *line && !ft_strisspace(line) && ft_strcmp(line, "<<"))
			add_history(line);
		if (line && *line && !ft_strisspace(line))
			ft_check_var_assign_and_expand_line(&data, line);
		if (line)
			free(line);
		line = NULL;
	}
	ft_cleanup_data(&data);
	return (g_last_exit_status);
}
