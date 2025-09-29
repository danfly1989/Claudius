/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:26:34 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/14 20:38:14 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int	result;

	result = 0;
	if (c >= 0 && c <= 127)
		result = 1;
	if (!(c >= 32 && c <= 126))
		result = 0;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	input;
	int	output;

	input = ' ';
	output = ft_isprint(input);
	printf("%d", output);
	return (0);
}*/
