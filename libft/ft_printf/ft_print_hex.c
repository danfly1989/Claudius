/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:47:08 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/10 22:19:45 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*hex;
	int		count;

	if (uppercase)
	{
		hex = "0123456789ABCDEF";
	}
	else
	{
		hex = "0123456789abcdef";
	}
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, uppercase);
	ft_printchar(hex[n % 16]);
	return (count + 1);
}
