/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 06:56:55 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 19:21:13 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*vm_rawread(int pc, int index, size_t size)
{
	static char	buf[READ_SIZE];
	int			i;
	int			s;

	i = -1;
	ft_bzero((void *)buf, READ_SIZE);
	size = size < READ_SIZE ? size : READ_SIZE;
	s = pc < index ? 1 : -1;
	index = pc + (s * (ft_abs(index - pc) % IDX_MOD));
	if (index + size < MEM_SIZE)
		ft_memcpy(buf, (g_arena + index), size);
	else
		while (++i < (int)size)
			buf[i] = g_arena[(index + i) % MEM_SIZE];
	return ((char *)buf);
}

char		*vm_lrawread(int index, size_t size)
{
	static char	buf[READ_SIZE];
	int			i;

	i = -1;
	ft_bzero((void *)buf, READ_SIZE);
	size = size < READ_SIZE ? size : READ_SIZE;
	if (index + size < MEM_SIZE)
		ft_memcpy(buf, (g_arena +index), size);
	else
		while (++i < (int)size)
			buf[i] = g_arena[(index + i) % MEM_SIZE];
	return ((char *)buf);
}

void		vm_write(int pc, int index, void *src, size_t size)
{
	int			i;
	int			s;

	i = -1;
	s = pc < index ? 1 : -1;
	index = pc + (s * (ft_abs(index - pc) % IDX_MOD));
	if (index + size < MEM_SIZE)
	{
		ft_memcpy((g_arena + index), src, size);
		endian_swap((g_arena + index), size);
	}
	else
		while (++i < (int)size)
			g_arena[(index + (size - 1 - i)) % MEM_SIZE] = *((char *)src + i);
}

void		vm_lwrite(int index, void *src, size_t size)
{
	int			i;

	i = -1;
	if (index + size < MEM_SIZE)
	{
		ft_memcpy((g_arena + index), src, size);
		endian_swap((g_arena + index), size);
	}
	else
		while (++i < (int)size)
			g_arena[(index + (size - 1 - i)) % MEM_SIZE] = *((char *)src + i);
}

void		vm_read(int pc, int index, void *dst, size_t size)
{
	index = pc + (ft_abs(index - pc) % IDX_MOD);
	ft_memcpy(dst, (g_arena + index), size);
	endian_swap((char *)dst, size);
}

void		vm_lread(int index, void *dst, size_t size)
{
	ft_memcpy(dst, (g_arena + index), size);
	endian_swap((char *)dst, size);
}
