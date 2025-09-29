/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:16:29 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:16:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parent_sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	g_last_exit_status = 130;
	rl_redisplay();
}

void	ft_child_sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		exit(130);
	}
	else if (sig == SIGQUIT)
	{
		exit(131);
	}
}

void	ft_nested_sigint_handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_redisplay();
	g_last_exit_status = 130;
}
