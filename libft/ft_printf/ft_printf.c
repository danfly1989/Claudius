/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:15:14 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/17 11:07:02 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_printchar(va_arg(args, int));
	else if (format == 's')
		count = ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count = ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count = ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count = ft_printchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += print_format(format[i], args);
		}
		else
		{
			count += ft_printchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void) {
  // quick hello world test using two string readings
  // ft_printf("Hello");
  // ft_printf("%s", " World");
  // ft_printf("\n");
  // check that it returns length of particular string
  // ft_printf(" %d", ft_printf("This prints first and the length is"));
  // ft_printf("%c", '\n');
  // printf(" %d", printf("This prints first and the length is"));
  // ft_printf("%s","\n");
  // ft_printf("\n");
  //
  ft_printf("print a lower hex number here: %x", 4000);
  ft_printf("\n");
  ft_printf("print a lower hex number here: %x", 4000);
}*/
