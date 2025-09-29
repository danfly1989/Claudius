/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:48:32 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/29 18:48:42 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str, const char *charset)
{
	size_t	len;
	int		found;
	size_t	i;

	len = 0;
	while (str[len])
	{
		found = 0;
		i = 0;
		while (charset[i])
		{
			if (str[len] == charset[i])
			{
				found = 1;
				break ;
			}
			i++;
		}
		if (!found)
			break ;
		len++;
	}
	return (len);
}
