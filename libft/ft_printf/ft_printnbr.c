/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:40:53 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/17 14:40:59 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_printchar('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_printnbr(n / 10);
	ft_printchar((n % 10) + '0');
	return (count + 1);
}
