/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:06:32 by mmoros            #+#    #+#             */
/*   Updated: 2018/05/28 12:53:48 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		free_parts(char **parts)
{
	int		i;

	if (parts)
	{
		i = -1;
		while (parts[++i])
			free(parts[i]);
		free(parts);
	}
	return (0);
}

int		set_fsm(char *line)
{
	char	**parts;

	parts = ft_strsplit(line, ' ');
	if (!fsm_set_op(parts[0]))
		return (free_parts(parts));
	if (g_fsm.bool_codebyte && !fsm_set_codebyte(parts + 1))
		return (free_parts(parts));
}

int		parse_file(char *filename)
{
	char	**input;

	input = get_clean_array(filename);
	while (*input)
	{
		
	}
}