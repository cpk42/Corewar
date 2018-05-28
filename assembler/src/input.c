/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 11:19:50 by mmoros            #+#    #+#             */
/*   Updated: 2018/05/28 12:40:03 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		count_lines(char *filename)
{
	int		fd;
	int		line_count;
	char	c;

	line_count = 0;
	if ((fd = fopen(filename)))
		return (0);
	while ((c = getc(fd)))
		if (c == '\n')
			line_count++;
	fclose(fd);
	ft_printf("file \"%s\" has %d lines\n", filename, line_count);
	return (line_count);
}

static char		**build_file_array(char *filename, int line_count)
{
	char	**lines;
	int		i;
	int		fd;

	if (!(lines = (char**)ft_memalloc(sizeof(char*) * (line_count + 1))))
		return (NULL);
	i = -1;
	if (!(fd = fopen(filename)))
		return (free_file_array(lines));
	while (++i < line_count)
	{
		if (get_next_line(fd, lines[i]) == -1)
			return (free_file_array(lines));
	}
}

char		**get_file_array(char *filename)
{
	char	**lines;
	int		line_count;

	ft_printf("Opening %s\n", filename);
	line_count = count_lines(filename);
	lines = build_file_array(filename, line_count);
}

void		*free_file_array(char **lines)
{
	int		i;

	if (lines)
	{
		i = -1;
		while (lines[++i])
			free(lines[i]);
		free(lines);
	}
	return (NULL);
}