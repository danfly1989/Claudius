/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:23:13 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 20:39:14 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	arr[] = {'a', 'b', 'c', 'd'};
	int		tab[] = {1, 2, 3, 4, 5};
	int		i;
	int		j;

	memset(1, 'x', 0);
	i = 0;
	while (i < 4)
	{
		printf("%c", arr[i]);
		i++;
	}
	j = 0;
	printf("\n");
	return (0);
}*/
