/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 06:56:55 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/18 10:35:18 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


int			write_to_arena(int index, char TYPE, t_val val)
{
	endian_swap((char *)&val, TYPE);
	ft_memcpy(&g_arena[index], &val, TYPE);
	return (1);
}

t_val		read_from_arena(int index, char TYPE)
{
	t_val		tmp;

	tmp.i = 0;
	if (TYPE == CHAR_TYPE)
		tmp.c = g_arena[index];
	else if (TYPE == SHORT_TYPE)
	{
		tmp.s = *(short *)(g_arena + index);
		endian_swap(&g_arena[index], SHORT_TYPE);
	}
	else if (TYPE == INT_TYPE)
	{
		tmp.i = *(int *)(g_arena + index);
		endian_swap(&g_arena[index], INT_TYPE);
	}
	return (tmp);
}
