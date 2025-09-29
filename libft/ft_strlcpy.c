/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:30 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 15:14:46 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(s);
	if (size == 0)
		return (src_size);
	while (i < size - 1 && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (src_size);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "abc";
	char	str2[] = "def";
	int		i;

	ft_strlcpy(str1, str2, 3);
	i = 0;
	while (i < 3)
	{
		printf("%c", str1[i]);
		i++;
	}
	return (0);
}*/
