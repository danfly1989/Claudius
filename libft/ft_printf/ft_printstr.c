/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:39:51 by daflynn           #+#    #+#             */
/*   Updated: 2025/01/17 14:39:58 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *s)
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
