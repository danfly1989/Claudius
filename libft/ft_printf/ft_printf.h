/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:56:30 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/10 18:00:09 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(const char *s);
int	ft_print_ptr(void *ptr);
int	ft_printnbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, int uppercase);

#endif
