/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:42:44 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/23 23:21:14 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_st(t_proc *ps)
{
	char			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = vm_rawread(ps->pc, ps->pc, 16);
	argtypes = extract_argtypes(bytes[1]);
	if (!has_legal_argtypes(bytes[0], argtypes))
		return (2);
	if (argtypes[1] == T_REG)
	{
		ps->regs[(int)(bytes[3])] = ps->regs[(int)(bytes[2])];
	}
	else // already checked for errors, right?
	{
		ind_offset = bigendian_num(bytes + 3, IND_SIZE);
		vm_write(ps->pc, ps->pc + ind_offset, ps->regs + bytes[2], REG_SIZE);
		//reg_mem_write(ar, ps, bytes[2], ind_offset);
	}
	return (instr_size(bytes[0], argtypes));
}
