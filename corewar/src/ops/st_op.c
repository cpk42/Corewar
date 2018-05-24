/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:42:44 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/23 20:13:27 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_st(byte *ar, t_proc *ps)
{
	byte			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = read_from_arena(ar, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
	if (!has_legal_argtypes(bytes[0], argtypes))
		return (2);
	if (argtypes[1] == T_REG)
	{
		ps->regs[bytes[3]] = ps->regs[bytes[2]];
	}
	else // already checked for errors, right?
	{
		ind_offset = bigendian_num(bytes + 3, IND_SIZE);
		reg_mem_write(ar, ps, bytes[2], ind_offset);
	}
	return (instr_size(bytes[0], argtypes));
}
