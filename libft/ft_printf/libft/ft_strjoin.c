/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                     +:+ +:+
	+:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:24:48 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/18 17:10:25 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**/
#include "libft.h"

void	init_counters(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

void	init_lens(size_t *total, char const *s1, char const *s2)
{
	*total = ft_strlen(s1) + ft_strlen(s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	init_counters(&i, &j);
	init_lens(&total, s1, s2);
	result = (char *)malloc(total + 1);
	if (!result)
		return (NULL);
	while (i < total)
	{
		if (i < ft_strlen(s1))
			result[i] = s1[i];
		else
			result[i] = s2[j++];
		i++;
	}
	result[total] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*output;
	int		i;

	s1 = "Hello ";
	s2 = "World";
	output = ft_strjoin(s1, s2);
	i = 0;
	while (output[i] != '\0')
	{
		printf("%c", output[i]);
		i++;
	}
	free(output);
	return (0);
}*/
