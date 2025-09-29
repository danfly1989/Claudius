/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:04:20 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 12:04:30 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_cmd_helper(t_dat *d, char ***cmd, int *idx, int *st_i)
{
	int	i;

	i = st_i[1];
	if (i < st_i[0])
		return (0);
	if (!ft_validate_segment(d->xln, st_i[0], i))
		return (0);
	cmd[*idx] = ft_extract_tokens(d, st_i[0], i);
	if (!cmd[*idx])
		return (0);
	(*idx)++;
	st_i[0] = i + 1;
	return (1);
}

char	***ft_parse_cmd(t_dat *d, int st, int i, int idx)
{
	char	***cmd;
	int		st_i[2];

	d->k = ft_count_pipes(d->xln) + 1;
	cmd = ft_calloc(d->k + 1, sizeof(char **));
	if (!cmd)
		return (NULL);
	st_i[0] = st;
	while (1)
	{
		st_i[1] = i;
		if (!d->xln[i] || !ft_strcmp(d->xln[i], "|"))
		{
			if (!ft_parse_cmd_helper(d, cmd, &idx, st_i))
				return (ft_clean_cmd(cmd));
			if (!d->xln[i])
				break ;
		}
		i++;
	}
	cmd[idx] = NULL;
	d->tot = idx;
	return (cmd);
}

int	ft_parse_redirection(char **tokens, t_rdr *r)
{
	int	i;

	i = 0;
	ft_memset(r, 0, sizeof(*r));
	while (tokens[i])
	{
		if (!ft_strcmp(tokens[i], "<") && tokens[i + 1])
			r->in_file = ft_strdup(tokens[++i]);
		else if (!ft_strcmp(tokens[i], ">") && tokens[i + 1])
			r->out_file = ft_strdup(tokens[++i]);
		else if (!ft_strcmp(tokens[i], ">>") && tokens[i + 1])
			r->append_file = ft_strdup(tokens[++i]);
		else if (!ft_strcmp(tokens[i], "<<") && tokens[i + 1])
			r->heredoc_delim = ft_strdup(tokens[++i]);
		i++;
	}
	return (1);
}
