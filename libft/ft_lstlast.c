/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:44:44 by daflynn           #+#    #+#             */
/*   Updated: 2024/12/09 19:11:56 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters lst: The beginning of the list.
Return value Last node of the list
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
