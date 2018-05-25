/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:55:49 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/24 23:08:04 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_or(t_proc *ps)
{
	t_arg_type	*argtypes;
	t_op		*op;
	int			args[4];

	ft_bzero(args, 4);
	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	fetch_args(argtypes, ps, (int *)args);
	if (!has_legal_argtypes(op, argtypes))
		return (2);
//	printf("\nmemory: %d %d %d %d %d %d %d %d\n", get_byte(ps, 0), get_byte(ps, 1), get_byte(ps, 2), get_byte(ps, 3), get_byte(ps, 4), get_byte(ps, 5), get_byte(ps, 6), get_byte(ps, 7));
	ps->regs[args[2] - 1] = args[0] | args[1];
	if (!ps->regs[args[2] - 1])
		ps->carry = 1;
	else
		ps->carry = 0;
	return (instr_size(op, argtypes));
}
