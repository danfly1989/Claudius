/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:17:20 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/15 13:40:32 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*input = "Hello world";
	char	*output = ft_strdup(input);

	if (output == NULL)
	{
		printf("Returned Null");
		return (1);
	}

	if(input == output)
	{
		printf("No true duplicate (same address)");
		return (2);
	}

	printf("OK!");
	//User must free memory for strdup
	free(output);
	return (0);
}*/
