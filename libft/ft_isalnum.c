/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:01:45 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/11 14:09:46 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char c)
{
	int	result;

	result = 0;
	if (c >= 'a' && c <= 'z')
		result = 1;
	if (c >= 'A' && c <= 'Z')
		result = 1;
	if (c >= '0' && c <= '9')
		result = 1;
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	input;
	int		output;

	input = 'A';
	output = ft_isalnum(input);
	printf("%d",output);
	return (0);
}
*/