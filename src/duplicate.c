/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:50:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/09/16 11:50:45 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_va	*ft_duplicate_node(const t_va *node)
{
	t_va	*new;

	new = malloc(sizeof(t_va));
	if (new == NULL)
		return (NULL);
	new->name = ft_strdup(node->name);
	new->value = ft_strdup(node->value);
	new->next = NULL;
	if (new->name == NULL || new->value == NULL)
	{
		free(new->name);
		free(new->value);
		free(new);
		return (NULL);
	}
	return (new);
}

int	ft_append_dup_node(const t_va *cur, t_va **head, t_va **tail)
{
	t_va	*new_node;

	new_node = ft_duplicate_node(cur);
	if (new_node == NULL)
	{
		ft_free_list(*head);
		return (0);
	}
	if (*tail == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}
	return (1);
}

t_va	*ft_duplicate_list(const t_va *head)
{
	const t_va	*cur;
	t_va		*new_head;
	t_va		*new_tail;

	cur = head;
	new_head = NULL;
	new_tail = NULL;
	while (cur != NULL)
	{
		if (!ft_append_dup_node(cur, &new_head, &new_tail))
			return (NULL);
		cur = cur->next;
	}
	return (new_head);
}

t_dat	ft_duplicate_input_args(int argc, char **argv, char **env)
{
	t_dat	data;

	(void)argc;
	data.av = NULL;
	data.ev = NULL;
	data.lo = NULL;
	data.ln = NULL;
	data.xln = NULL;
	data.tmp1 = NULL;
	data.tmp2 = NULL;
	data.i = 0;
	data.j = 0;
	data.k = 0;
	data.tot = 0;
	data.st = 0;
	data.no_pipes = 0;
	data.avs = NULL;
	data.evs = NULL;
	data.qtypes = NULL;
	data.av = create_lst_frm_arr(argv + 1, NULL, 0, ft_create_node);
	data.ev = create_lst_frm_arr(env, NULL, 0, ft_create_var_node);
	ft_increment_shlvl(&data.ev);
	return (data);
}
