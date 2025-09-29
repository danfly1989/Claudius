/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:01:16 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 12:01:23 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Always return the path for relative/absolute paths
Let	execve(void) determine if it's valid. This function was
formerly using access incorrectly before letting it jump
to execve, resulting in incorrect error codes.*/
char	*ft_get_cmd_path_nested(const char *cmd)
{
	return (ft_strdup(cmd));
}

char	*ft_get_cmd_path(t_dat *d, const char *cmd, int i)
{
	char	*full;

	if (!cmd || *cmd == '\0')
		return (NULL);
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		return (ft_get_cmd_path_nested(cmd));
	d->tmp1 = ft_get_val_from_list(d->ev, "PATH");
	if (!d->tmp1)
		return (NULL);
	d->avs = ft_split(d->tmp1, ':');
	while (d->avs && d->avs[i])
	{
		full = ft_join_path(d->avs[i], (char *)cmd);
		if (access(full, X_OK) == 0)
		{
			ft_free_string_array(d->avs);
			return (full);
		}
		free(full);
		i++;
	}
	ft_free_string_array(d->avs);
	return (NULL);
}

void	ft_cmd_not_found(char *cmd)
{
	char	*prefix;
	char	*suffix;

	prefix = "minishell: ";
	suffix = ": command not found\n";
	write(2, prefix, ft_strlen(prefix));
	write(2, cmd, ft_strlen(cmd));
	write(2, suffix, ft_strlen(suffix));
	exit(127);
}

void	ft_cmd_error(t_dat *data, char *line)
{
	(void)line;
	ft_free_string_array(data->evs);
	data->evs = NULL;
	return ;
}
