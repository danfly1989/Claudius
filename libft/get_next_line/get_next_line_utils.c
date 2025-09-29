/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:19:56 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/12 20:43:32 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substring(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(end - start + 1);
	i = 0;
	while (i < end - start)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}
