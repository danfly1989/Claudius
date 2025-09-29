/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:15:29 by daflynn           #+#    #+#             */
/*   Updated: 2024/12/01 14:17:57 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_same(const char *big, const char *little, size_t start_index, size_t len)
{
	size_t	i;
	size_t	j;

	i = start_index;
	j = 0;
	while (little[j] != '\0' && i < len)
	{
		if ((unsigned char)big[i] != (unsigned char)little[j])
			return (0);
		i++;
		j++;
	}
	return (little[j] == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!big || !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (i + little_len <= len && big[i] == little[0])
		{
			if (is_same(big, little, i, len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	big[] = "There is something in here";
	char	small[] = "is";
	char	*output;

	output = ft_strnstr(big, small, 20);
	printf("%s", output);
	return (0);
}*/
