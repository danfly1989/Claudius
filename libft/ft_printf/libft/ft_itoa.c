/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:13:38 by daflynn           #+#    #+#             */
/*   Updated: 2024/12/01 13:03:15 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct t_declarations
{
	int				len;
	char			*result;
	unsigned int	un;
}					t_declarations;

size_t	num_len(int n)
{
	int				len;
	unsigned int	un;

	un = (unsigned int)n;
	len = 0;
	if (n < 0)
	{
		len++;
		un = ((unsigned int)(-(1 + n))) + 1;
	}
	while (un > 0)
	{
		len++;
		un = un / 10;
	}
	if (n == 0)
		return (1);
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	t_declarations	vars;

	vars.len = num_len(n);
	result = (char *)malloc((vars.len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[vars.len] = '\0';
	vars.un = (unsigned int)n;
	if (n < 0)
		result[0] = '-';
	if (n < 0)
		vars.un = 1 + (unsigned int)(-(n + 1));
	if (vars.un == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	while (vars.un > 0)
	{
		result[--vars.len] = vars.un % 10 + '0';
		vars.un /= 10;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*output;

	output = ft_itoa(123);
	printf("%s", output);
	return (0);
}*/
