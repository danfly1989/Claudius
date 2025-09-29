/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:05:59 by daflynn           #+#    #+#             */
/*   Updated: 2025/02/21 11:23:37 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// covers case for both error < 0 and the case for end of file = 0
// IF READ FAILED, free buffer and return NULL
// if EOF REACHED, check for data. If data return buffer val after free
// if buffer is an empty string(""), free and return NULL
char	*end_states(ssize_t read_value, char **buffer)
{
	char	*temp;

	if (read_value < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	else
	{
		if (*buffer && **buffer)
		{
			temp = ft_strdup(*buffer);
			free(*buffer);
			*buffer = NULL;
			return (temp);
		}
		else
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
	}
	return (*buffer);
}

// uses pointer arithmetic from strchr to locate appropriate section
// of buffer (after null terminator and before buffer end) to section
// off remaning bytes for next iteration
void	create_remaining(char **retainer, char **buffer)
{
	char	*first_newline_ptr;

	first_newline_ptr = ft_strchr(*buffer, '\n');
	if (first_newline_ptr)
	{
		*retainer = ft_substring(*buffer, first_newline_ptr - (*buffer) + 1,
				ft_strlen(*buffer));
		if (first_newline_ptr)
			(*buffer)[first_newline_ptr - *buffer + 1] = '\0';
	}
	else
		*retainer = NULL;
}

// reads and joins components to static buffer before returning unused remainder
// if read is unsuccessful or file complete,
// the end state functions are triggered
char	*reader(int fd, char **buffer)
{
	char	*component;
	char	*retainer;
	ssize_t	read_value;
	char	*temp;

	while (!ft_strchr(*buffer, '\n'))
	{
		component = malloc(BUFFER_SIZE + 1);
		if (!component)
			return (free(*buffer), NULL);
		read_value = read(fd, component, BUFFER_SIZE);
		if (read_value > 0)
		{
			component[read_value] = '\0';
			temp = ft_strjoin(*buffer, component);
			free(component);
			free(*buffer);
			*buffer = temp;
		}
		else
			return (free(component), end_states(read_value, buffer));
	}
	create_remaining(&retainer, buffer);
	return (retainer);
}

// checks for error case and calls reader to create line to return if valid,
//	NULL if not
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*remainder;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	remainder = reader(fd, &buffer);
	if (!remainder)
	{
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
	{
		line = ft_strdup(remainder);
		return (free(remainder), line);
	}
	line = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	if (ft_strlen(remainder) > 0)
		buffer = ft_strdup(remainder);
	return (free(remainder), line);
}
