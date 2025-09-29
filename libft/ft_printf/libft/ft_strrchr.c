/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:49:16 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/12 16:34:05 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	int				end;
	unsigned char	ch;

	ch = (unsigned char)c;
	end = ft_strlen(str);
	while (end >= 0)
	{
		if (str[end] == ch)
		{
			return (&str[end]);
		}
		end--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	input_str[] = "abcdefabcdef";
	char	input_char;
	char	*output;

	input_char = 'd';
	output = ft_strrchr(input_str, input_char);
	if (output != 0)
		printf("%ld", output - input_str);
	return (0);
}*/
