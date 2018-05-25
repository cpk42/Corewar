/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:42:44 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/24 14:10:47 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_st(t_proc *ps)
{
	t_arg_type		*argtypes;
	int				ind_offset;
	t_op			*op;

	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	if (argtypes[1] == T_REG)
	{
		ps->regs[get_byte(ps, 3) - 1] = ps->regs[get_byte(ps, 2) - 1];
	}
	else // already checked for errors, right?
	{
		assert(argtypes[1] == T_IND);
		ind_offset = follow_indirect_reference(ps, 3);
		store_register_contents(ps, get_byte(ps, 2) - 1, ind_offset);
	}
	return (instr_size(op, argtypes));
}
