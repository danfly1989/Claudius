/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:14:12 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/17 21:14:53 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the character ’c’ to the given file
descriptor.
*/

#include "libft.h"

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	return (0);
}*/
