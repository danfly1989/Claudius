/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:33:46 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/11 14:00:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char input = 'v';
	int output;

	output	= ft_toupper(input);
	printf("%c", output);
	return (0);
}*/
