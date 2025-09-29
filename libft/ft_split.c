/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:59:47 by daflynn           #+#    #+#             */
/*   Updated: 2024/12/06 15:41:21 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_freeup(char **strs, int i)
{
	while (i--)
		free(strs[i]);
	free(strs);
}

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_stralloc(const char *s, char c, int *pos)
{
	int		len;
	char	*word;
	int		start;

	while (s[*pos] == c && s[*pos] != '\0')
		(*pos)++;
	start = *pos;
	len = 0;
	while (s[*pos] && s[*pos] != c)
	{
		(*pos)++;
		len++;
	}
	if (len == 0)
		return (NULL);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[start], len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		pos;
	int		word_count;

	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	word_count = ft_wordcount(s, c);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strs)
		return (NULL);
	strs[word_count] = NULL;
	while (i < word_count)
	{
		strs[i] = ft_stralloc(s, c, &pos);
		if (!strs[i])
		{
			ft_freeup(strs, i);
			return (NULL);
		}
		i++;
	}
	return (strs);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*input_str;
	char		input_char;
	char		**output;

	int i, j, x, y;
	i = 0, j = 0, x = 0, y = 0;
	input_str = "Thisccccciscccaclongcstring";
	input_char = 'c';
	output = ft_split(input_str, input_char);
	while (output[i] != NULL)
	{
		j = 0;
		while (output[i][j] != '\0')
		{
			printf("%c", output[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	while (output[x] != NULL)
	{
		free(output[x]);
		x++;
	}
	free(output);
	return (0);
}*/
