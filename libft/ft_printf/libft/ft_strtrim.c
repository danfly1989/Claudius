/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:00:27 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/16 13:51:54 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && is_in_set(s[start], set))
		start++;
	end = ft_strlen(s);
	while (end > start && is_in_set(s[end - 1], set))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s + start, end - start + 1);
	return (trimmed);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "      %  % Hi my guy!   %   ";
	char *set = " % ";
	char *output = ft_strtrim(str, set);
	int i = 0;

	printf("start index is: %d \n", ft_start_index(str, set));
	printf("end index is: %d \n", ft_end_index(str, set));
	printf("\n\n");
	while (output[i] != '\0')
	{
		printf("%c", output[i]);
		i++;
	}

	return (0);
}*/