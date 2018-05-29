/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:56:35 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/28 20:18:04 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_ld(t_proc *ps)
{
	t_arg_type	*argtypes;
	t_op		*op;

	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	if (argtypes[0] == T_DIR)
		ps->regs[get_byte(ps, 6) - 1] = get_int(ps, 2);
	else
		ps->regs[get_byte(ps, 4) - 1] = follow_indirect_reference(ps, 2);
	return (instr_size(op, argtypes));
}
