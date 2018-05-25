/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:56:35 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/24 20:26:02 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_ld(t_proc *ps)
{
	t_arg_type	*argtypes;
	int			ind_offset;
	t_op		*op;

	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	if (argtypes[0] == T_DIR)
		ps->regs[get_byte(ps, 6) - 1] = get_int(ps, 2);
	else
	{
		ind_offset = follow_indirect_reference(ps, 3);
		ps->regs[get_byte(ps, 5) - 1] = ind_offset;
	}
	return (instr_size(op, argtypes));
}
