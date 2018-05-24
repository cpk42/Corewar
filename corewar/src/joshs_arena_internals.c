/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joshs_arena_internals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:26:51 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/24 14:33:12 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*_process_read(t_proc *ps, int req_idx, size_t size)
{
	static char		buf[16];
	size_t			i;
	size_t			real_idx;

	ft_bzero(buf, sizeof(buf));
	i = 0;
	while (i < size)
	{
		real_idx = (ps->pc + ((req_idx + i) % IDX_MOD)) % MEM_SIZE;
		buf[i] = g_arena[real_idx];
		++i;
	}
	return ((char *)buf);
}

char		*_process_lread(t_proc *ps, int req_idx, size_t size)
{
	static char		buf[16];
	size_t			i;
	size_t			real_idx;

	ft_bzero(buf, sizeof(buf));
	i = 0;
	while (i < size)
	{
		real_idx = (ps->pc + req_idx + i) % MEM_SIZE;
		buf[i] = g_arena[real_idx];
		++i;
	}
	return ((char *)buf);
}

void		_store_register_contents(t_proc *ps, int reg_idx, int req_idx)
{
	size_t	i;
	size_t	real_idx;
	int		n;

	n = ps->regs[reg_idx];
	req_idx += sizeof(n) - 1;
	i = 0;
	while (i < sizeof(n))
	{
		real_idx = (ps->pc + ((req_idx - i) % IDX_MOD)) % MEM_SIZE;
		g_arena[real_idx] = ((char *)&n)[i];
		++i;
	}
}

void		_lstore_register_contents(t_proc *ps, int reg_idx, int req_idx)
{
	size_t	i;
	size_t	real_idx;
	int		n;

	n = ps->regs[reg_idx];
	req_idx += sizeof(n) - 1;
	i = 0;
	while (i < sizeof(n))
	{
		real_idx = (ps->pc + req_idx - i) % MEM_SIZE;
		g_arena[real_idx] = ((char *)&n)[i];
		++i;
	}
}

/*
** For getting an actual number out of a string of bytes. We can't just read
** the memory and cast to (int) or (short) because the endianness will be wrong.
*/

unsigned long	bigendian_num(char *buf, size_t size)
{
	unsigned long res;
	unsigned long x;

	res = 0;
	while (size > 0)
	{
		x = (unsigned long)(*buf);
		x = x << ((size - 1) * 8);
		res |= x;
		--size;
		++buf;
	}
	return (res);
}
