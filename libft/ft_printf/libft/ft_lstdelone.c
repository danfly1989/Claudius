/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:33:54 by daflynn           #+#    #+#             */
/*   Updated: 2024/12/09 19:41:11 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
