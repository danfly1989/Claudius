/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:30:21 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/11 14:01:12 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	int	result;

	result = 0;
	if (c >= 'a' && c <= 'z')
		result = 1;
	if (c >= 'A' && c <= 'Z')
		result = 1;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char  input = ' ';
	int output = ft_isalpha(input);
	printf("%d", output);
	return (0);
}*/
