/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:39:25 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/23 23:24:31 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_sti(t_proc *ps)
{
	char			*bytes;
	t_arg_type		*argtypes;
	int				next_arg_start_idx;
	unsigned long	dst_address;

	bytes = vm_rawread(ps->pc, ps->pc, 16);
	argtypes = extract_argtypes(bytes[1]);
	if (!has_legal_argtypes(bytes[0], argtypes))
		return (2);
	dst_address = 0;
	assert(argtypes[0] == T_REG);
	next_arg_start_idx = 3;
	if (argtypes[1] == T_REG)
	{
		dst_address += ps->regs[(int)(bytes[3])];
		next_arg_start_idx += 1;
	}
	else if (argtypes[1] == T_IND)
	{
		dst_address += bigendian_num(bytes + 3, IND_SIZE);
		next_arg_start_idx += IND_SIZE;
	}
	else
	{
		assert(argtypes[1] == T_DIR);
		dst_address += bigendian_num(bytes + next_arg_start_idx, TRUNCATED_DIR_SIZE);
		next_arg_start_idx += TRUNCATED_DIR_SIZE;
	}
	if (argtypes[2] == T_REG)
	{
		dst_address += ps->regs[(int)(bytes[next_arg_start_idx])];
	}
	else
	{
		assert(argtypes[2] == T_DIR);
		dst_address += bigendian_num(bytes + next_arg_start_idx, TRUNCATED_DIR_SIZE);
	}
	vm_write(ps->pc, ps->pc + dst_address, ps->regs + bytes[2], REG_SIZE);
	return (instr_size(bytes[0], argtypes));
}