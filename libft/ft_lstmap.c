/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:14:29 by daflynn           #+#    #+#             */
/*   Updated: 2024/12/09 20:14:58 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed
*/

#include "libft.h"

typedef struct t_declarations
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

}			t_declarations;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_declarations	vars;

	vars.new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		vars.content = f(lst->content);
		if (!vars.content)
		{
			ft_lstclear(&vars.new_list, del);
			return (NULL);
		}
		vars.new_node = ft_lstnew(vars.content);
		if (!vars.new_node)
		{
			del(vars.content);
			ft_lstclear(&vars.new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&vars.new_list, vars.new_node);
		lst = lst->next;
	}
	return (vars.new_list);
}
