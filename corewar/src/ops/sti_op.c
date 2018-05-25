/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:39:25 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/24 16:51:14 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_sti(t_proc *ps)
{
	t_arg_type		*argtypes;
	int				next_arg_start_idx;
	unsigned long	dst_address;
	t_op			*op;

	argtypes = extract_argtypes(get_byte(ps, 1));
	op = PROCESS_CURRENT_OP(ps);
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	dst_address = 0;
	assert(argtypes[0] == T_REG);
	next_arg_start_idx = 3;
	if (argtypes[1] == T_REG)
	{
		dst_address += ps->regs[get_byte(ps, 3) - 1];
		next_arg_start_idx += 1;
	}
	else if (argtypes[1] == T_IND)
	{

		dst_address += follow_indirect_reference(ps, 3);
		next_arg_start_idx += IND_SIZE;
	}
	else
	{
		assert(argtypes[1] == T_DIR);
		dst_address += get_short(ps, next_arg_start_idx);
		next_arg_start_idx += TRUNCATED_DIR_SIZE;
	}
	if (argtypes[2] == T_REG)
	{
		dst_address += ps->regs[get_byte(ps, next_arg_start_idx) - 1];
	}
	else
	{
		assert(argtypes[2] == T_DIR);
		dst_address += get_short(ps, next_arg_start_idx);
	}
	store_register_contents(ps, get_byte(ps, 2) - 1, dst_address);
	return (instr_size(op, argtypes));
}
