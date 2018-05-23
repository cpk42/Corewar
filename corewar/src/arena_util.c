/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 06:56:55 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 15:36:42 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		vm_write(int pc, int index, void *src, unsigned int size)
{
	index = pc + (index % IDX_MOD)
	ft_memcpy((g_arena + index), src, size);
	endian_swap((g_arena + index), size);
}

void		vm_read(int pc, int index, void *dst, unsigned int size)
{
	ft_memcpy(dst, (g_arena + index), size);
	endian_swap((char *)dst, size);
}

void		vm_lwrite(int index, void *src, unsigned int size)
{
	endian_swap((char *)src, size);
	ft_memcpy((g_arena + index), src, size);
}

void		vm_lread(int index, void *dst, unsigned int size)
{
	ft_memcpy(dst, (g_arena + index), size);
	endian_swap((char *)dst, size);
}
