/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:44:38 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/11 14:00:09 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char c)
{
	char	result;

	result = 0;
	if (c >= '0' && c <= '9')
		result = 1;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	input;
	input = '9';
	int	output;
	output = ft_isdigit(input);
	printf("%d", output);
	return (0);
}*/
