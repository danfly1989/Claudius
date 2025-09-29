/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:17:02 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 20:36:41 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	result;

	result = 0;
	if (c >= 0 && c <= 127)
	{
		result = 1;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	input;
	int	output;

	input = 200;
	output = ft_isascii(input);
	printf("%d", output);
	return (0);
}*/
