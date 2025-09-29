/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:20:42 by daflynn           #+#    #+#             */
/*   Updated: 2024/11/17 19:49:16 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;
	size_t	len;

	if (!s || !f)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char const		*input;
	char			c;
	char			*output;
	unsigned int	goo;
	int				i;

	goo = 1;
	input = "00000000";
	c = 'a';
	output = ft_strmapi(input, sample_func);
	i = 0;
	while (output[i] != '\0')
	{
		printf("%c", output[i]);
		i++;
	}
	free(output);
}*/
