/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:31:01 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/24 16:09:14 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	dptr = (unsigned char *)s1;
	sptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (dptr[i] != sptr[i])
			return (dptr[i] - sptr[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{

	int output = ft_memcmp("t\200", "t\0", 2);
	printf("%d", output);


	return (0);
}*/
