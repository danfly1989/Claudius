/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:44:09 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/18 16:57:55 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	input[] = "Here we go";
	char	*output;
	int		i;

	output = ft_substr(input, 1, 20);
	i = 0;
	while (output[i] != '\0')
	{
		printf("%c", output[i]);
		i++;
	}
	free(output);
	return (0);
}*/
