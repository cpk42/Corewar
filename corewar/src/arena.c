/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:20:11 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/23 19:34:02 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Most reads are for temporary reference only, but it's convenient to
** be able to reference an object that persists for the length of the call,
** so we'll use a static buffer. No particular reason to use 16.
*/

byte		*read_from_arena(byte *ar, size_t size, int pc)
{
	static byte		buf[16];
	size_t			i;
	size_t			real_idx;

	ft_bzero(buf, sizeof(buf));
	i = 0;
	while (i < size)
	{
		real_idx = (pc + i) % IDX_MOD % MEM_SIZE;
		buf[i] = ar[real_idx];
		++i;
	}
	return ((byte *)buf);
}

byte		*lread_from_arena(byte *ar, size_t size, int pc)
{
	static byte		buf[16];
	size_t			i;
	size_t			real_idx;

	ft_bzero(buf, sizeof(buf));
	i = 0;
	while (i < size)
	{
		real_idx = (pc + i) % MEM_SIZE;
		buf[i] = ar[real_idx];
		++i;
	}
	return ((byte *)buf);
}

/*
** Unlikely to be used by the main program, because the only writes done are
** from (little-endian) registers, which should use write_from_register.
*/
void		raw_arena_write(byte *ar, void *src, size_t size, int req_idx)
{
	size_t	i;
	size_t	real_idx;

	i = 0;
	while (i < size)
	{
		real_idx = (req_idx + i) % MEM_SIZE;
		ar[real_idx] = ((byte *)src)[i];
		++i;
	}
}

void		write_backwards(byte *ar, void *src, size_t size, int pc, int req_idx)
{
	size_t	i;
	size_t	real_idx;

	i = 0;
	req_idx += size - 1;
	while (i < size)
	{
		real_idx = (pc + ((req_idx - i) % IDX_MOD)) % MEM_SIZE;
		ar[real_idx] = ((byte *)src)[i];
		++i;
	}
}

void		lwrite_backwards(byte *ar, void *src, size_t size, int pc, int req_idx)
{
	size_t	i;
	size_t	real_idx;

	i = 0;
	req_idx += size - 1;
	while (i < size)
	{
		real_idx = (pc + req_idx - i) % MEM_SIZE;
		ar[real_idx] = ((byte *)src)[i];
		++i;
	}
}

/*
** Another convenience function. NOTE: This assumes that registers
** hold normal little-endian numbers, and hence need to be written backwards.
** It seems convenient to have them do that for arithmetic purposes, but if
** that stops being true this should become a simple forwards write.
*/

void		reg_mem_write(byte *ar, t_proc *ps, int reg_idx, int dst_idx)
{
	write_backwards(ar, &(ps->regs[reg_idx]), REG_SIZE, ps->pc, dst_idx);
}

void		lreg_mem_write(byte *ar, t_proc *ps, int reg_idx, int dst_idx)
{
	lwrite_backwards(ar, &(ps->regs[reg_idx]), REG_SIZE, ps->pc, dst_idx);
}
