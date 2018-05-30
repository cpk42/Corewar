/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:56:35 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/29 19:50:49 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_ld(t_proc *ps)
{
	t_arg_type	*argtypes;
	int			args[4];
	t_op		*op;
	
	ft_bzero(args, 4);
	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	fetch_args(op, argtypes, ps, args);
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	ps->regs[args[1] - 1] = args[0];
	if (!ps->regs[args[1]])
		ps->carry = 1;
	else
		ps->carry = 0;
	return (instr_size(op, argtypes));
}
