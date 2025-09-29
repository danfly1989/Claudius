/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:23:49 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 20:39:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};

	int i =0;
	ft_bzero(arr, 5 * sizeof(int));

	while (i<5)
	{
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}*/
