/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:56:22 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/10 18:16:52 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrbase(unsigned long num, char *base, int *len)
{
	if (num > 15)
		ptrbase((num / 16), base, len);
	*len += 1;
	return (write(1, &base[num % 16], 1));
}

int	ft_print_ptr(void *ptr)
{
	int				len;
	unsigned long	i;

	len = 0;
	if (ptr == NULL)
	{
		len += 5;
		write(1, "(nil)", 5);
	}
	else
	{
		i = (unsigned long)ptr;
		write(1, "0x", 2);
		len += 2;
		ptrbase(i, "0123456789abcdef", &len);
	}
	return (len);
}
