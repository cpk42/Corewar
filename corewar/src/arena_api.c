/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_api.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:49:46 by jgelbard          #+#    #+#             */
/*   Updated: 2018/06/04 15:35:23 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define OP_USES_IDX_MOD(op) (op->opcode != LLD && op->opcode != LLDI && op->opcode != LFORK)

void		store_register_contents(t_proc *ps, int reg_idx, int req_idx)
{
	int		n;

	t_op *op;
	n = ps->regs[reg_idx];
	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		vm_write(ps->pc, req_idx, &n, 4);
	else
		vm_lwrite(ps->pc + req_idx, &n, 4);
}

long			follow_indirect_reference(t_proc *ps, int idx_of_indirect)
{
	long	res;
	short	ind;

	ind = get_short(ps, idx_of_indirect);
	res = get_int(ps, ind);
	return (res);
}

long			get_int(t_proc *ps, int req_idx)
{
	long	res;
	char	*bytes;
	t_op	*op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		bytes = vm_rawread(ps->pc, req_idx, 4);
	else
		bytes = vm_lrawread(ps->pc + req_idx, 4);
	res = bigendian_num(bytes, 4);
	return (res);
}

long			get_short(t_proc *ps, int req_idx)
{
	long	res;
	char	*bytes;
	t_op	*op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		bytes = vm_rawread(ps->pc, req_idx, 2);
	else
		bytes = vm_lrawread(ps->pc + req_idx, 2);

	res = bigendian_num(bytes, 2);
	return (res);
}

long			get_byte(t_proc *ps, int req_idx)
{
	long	res;
	char	*bytes;
	t_op	*op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		bytes = vm_rawread(ps->pc, req_idx, 1);
	else
		bytes = vm_lrawread(ps->pc + req_idx, 1);
	res = bigendian_num(bytes, 1);
	return (res);
}

/*
** For getting an actual number out of a string of bytes. We can't just read
** the memory and cast to (int) or (short) because the endianness will be wrong.
*/

unsigned long	bigendian_num(char *buf, size_t size)
{
	unsigned long	res;
	char			*pres;

	res = 0;
	pres = (char *)&res;
	while (size--)
		*pres++ = buf[size];
	return (res);
}
