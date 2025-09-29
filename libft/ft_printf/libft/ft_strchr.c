/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:12:19 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/11 18:10:32 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if (ch == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*input_str;
	char	input_char;
	char	*result;

	input_str = NULL;
	input_char = 'd';
	result = strchr(input_str, input_char);
	if (result != 0)
	{
		printf("'%c' found at position: %ld\n", input_char, result - input_str);
	}
	else
	{
		printf("'%c' not found in the string. \n", input_char);
	}
	return (0);
}*/
