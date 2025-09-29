/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:28:59 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/10 20:29:01 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}
