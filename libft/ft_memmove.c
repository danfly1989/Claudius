/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:33:09 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/18 16:52:18 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	i = 0;
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (dptr > sptr && dptr < sptr + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dptr[i] = sptr[i];
		}
	}
	else
	{
		while (i < n)
		{
			dptr[i] = sptr[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	*d_input;
	char	*s_input;
	char	*output;

	d_input = "sdf";
	s_input = "asdf";
	output = ft_memmove(d_input,s_input,2);
	return (0);
}
*/
