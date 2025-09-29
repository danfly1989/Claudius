/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:31:15 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 20:44:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, unsigned int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	*ptr1;
	int	*ptr2;
	int	arr[] = {'a', 'b', 'c', 'd'};

	ptr1 = memchr(arr, 'd', 0);
	ptr2 = ft_memchr(arr, 'd', 0);
	printf("%ld", ptr1 - arr);
	printf("\n");
	printf("%ld", ptr2 - arr);
	return (0);
}*/
