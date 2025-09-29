/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:04 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 19:00:53 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *nb)
{
	int	result;
	int	i;
	int	sign;

	if (ft_strncmp(nb, "-2147483648", 11) == 0)
		return (-2147483648);
	sign = 1;
	result = 0;
	i = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || (nb[i] == ' '))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign = -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + (nb[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*input;
	int		output;

	input = "-21474836\b";
	output = atoi(input);
	printf("%d", output);
	return (0);
}
*/