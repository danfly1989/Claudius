/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:04:53 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/24 16:15:31 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = dest;
	sptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	int	arr1[] = {1, 2, 3};
	int	arr2[] = {4, 5, 6};
	int	i;

	ft_memcpy(arr1, arr2, 3 * sizeof(int));
	i = 0;
	while (i < 3)
	{
		printf("%d", arr1[i]);
		i++;
	}
	return (0);
}*/
