/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joshs_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:27:43 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/24 14:33:12 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define OP_USES_IDX_MOD(op) (op->opcode != LLD && op->opcode != LLDI && op->opcode != LFORK)

void		store_register_contents(t_proc *ps, int reg_idx, int req_idx)
{
	t_op *op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		_store_register_contents(ps, reg_idx, req_idx);
	else
		_lstore_register_contents(ps, reg_idx, req_idx);
}

int			follow_indirect_reference(t_proc *ps, int idx_of_indirect)
{
	int		res;
	short	ind;

	char *bytes = vm_rawread(ps->pc, ps->pc + idx_of_indirect, 2);
	ind = get_short(ps, idx_of_indirect);
	bytes = vm_rawread(ps->pc, ps->pc + ind, 4);
	res = get_int(ps, ind);
	return (res);
}

int			get_int(t_proc *ps, int req_idx)
{
	int		res;
	char	*bytes;
	t_op	*op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		bytes = _process_read(ps, req_idx, 4);
	else
		bytes = _process_lread(ps, req_idx, 4);
	res = bigendian_num(bytes, 4);
	return ((int)res);
}

int			get_short(t_proc *ps, int req_idx)
{
	int		res;
	char	*bytes;
	t_op	*op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		bytes = _process_read(ps, req_idx, 2);
	else
		bytes = _process_lread(ps, req_idx, 2);
	res = bigendian_num(bytes, 2);
	return ((int)res);
}

int			get_byte(t_proc *ps, int req_idx)
{
	int		res;
	char	*bytes;
	t_op	*op;

	op = PROCESS_CURRENT_OP(ps);
	if (OP_USES_IDX_MOD(op))
		bytes = _process_read(ps, req_idx, 1);
	else
		bytes = _process_lread(ps, req_idx, 1);
	res = bigendian_num(bytes, 1);
	return ((int)res);
}
