/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:20:11 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/21 23:12:26 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Most reads are for temporary reference only, but it's convenient to
** be able to reference an object that persists for the length of the call,
** so we'll use a static buffer. No particular reason to use 16.
*/

byte		*read_from_arena(byte *ar, int start_idx, size_t size, int pc)
{
	static byte		buf[16];
	size_t			i;

	ft_bzero(buf, sizeof(buf));
	i = 0;
	while (i < size)
	{
		buf[i] = ar[MEMSAFE(LEASH(start_idx + i, pc))];
		++i;
	}
	return ((byte *)buf);
}

void		write_to_arena(byte *ar, int start_idx, size_t size, int pc, void *bytes)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ar[MEMSAFE(LEASH(start_idx + i, pc))] = ((byte *)bytes)[i];
		++i;
	}
}

void		write_backwards(byte *ar, int idx, size_t size, int pc, void *bytes)
{
	size_t	i;

	i = 0;
	idx += size - 1;
	while (i < size)
	{
		ar[MEMSAFE(LEASH(idx, pc))] = ((byte *)bytes)[i];
		++i;
		--idx;
	}
}

/*
** This is a convenience function to save on typing ampersands and parens.
** Writing from register to register is just a memcpy.
*/
void		reg_reg_write(t_proc *ps, int dst_reg, int src_reg)
{
	memcpy(&(ps->regs[dst_reg]), &(ps->regs[src_reg]), REG_SIZE);
}

/*
** Another convenience function. NOTE: This assumes that registers
** hold normal little-endian numbers, and hence need to be written backwards.
** It seems convenient to have them do that for arithmetic purposes, but if
** that stops being true this should become a simple forwards write.
*/

void		reg_mem_write(t_proc *ps, int dst_idx, int src_reg, byte *ar)
{
	write_backwards(ar, dst_idx, REG_SIZE, ps->pc, &(ps->regs[src_reg]));
}
