/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:59:30 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/28 20:31:05 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_ldi(t_proc *ps)
{
	t_arg_type	*argtypes;
	t_op		*op;
	int			args[4];
	int			sum;

	ft_bzero(args, 4);
	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	fetch_args(op, argtypes, ps, args);
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	sum = args[0] + args[1];
	ps->regs[args[2] - 1] = get_int(ps, sum);
	if (!sum)
		ps->carry = 1;
	else
		ps->carry = 0;
	return(instr_size(op, argtypes));
}
