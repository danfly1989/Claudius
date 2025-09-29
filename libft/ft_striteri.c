/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:22:32 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/17 20:23:45 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

/*
int	main(void)
{
	char	*input_str;
	char	input_char;

	input_str = "abcdefg";
	input_char = 'c';
	ft_striteri(input_str, sample_func);
	return (0);
}*/
