/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:55:49 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/24 20:13:21 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_add(t_proc *ps)
{
	t_arg_type	*argtypes;
	t_op		*op;

	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	if (!has_legal_argtypes(op, argtypes))
		return (2);
//	printf("%d %d %d %d %d\n", get_byte(ps, 0), get_byte(ps, 1), get_byte(ps, 2), get_byte(ps, 3), get_byte(ps, 4));
	ps->regs[get_byte(ps, 4) - 1] = ps->regs[get_byte(ps, 2) - 1] + ps->regs[get_byte(ps, 3) - 1];
	if (!ps->regs[get_byte(ps, 4) - 1])
		ps->carry = 1;
	else
		ps->carry = 0;
	return (instr_size(op, argtypes));
}
