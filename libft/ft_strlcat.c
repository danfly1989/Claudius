/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:16:25 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/27 14:16:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if ((dest_len + i) < size)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "abc";
	str2 = "def";
	ft_strlcat(str1, str2, 3);
	printf("%s", str1);
	return (0);
}
*/