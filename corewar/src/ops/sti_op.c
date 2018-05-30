/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:39:25 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/29 16:29:02 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_sti(t_proc *ps)
{
	t_arg_type	*argtypes;
	int			args[4];
	t_op		*op;
	int			val1;
	int			val2;

	ft_bzero(args, 4);
	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	fetch_args(op, argtypes, ps, args);
	val1 = (IS_REG(argtypes[1]) ? ps->regs[args[1] - 1] : args[1]);
	val2 = (IS_REG(argtypes[2]) ? ps->regs[args[2] - 1] : args[2]);
	store_register_contents(ps, args[0] - 1, val1 + val2);
	return (instr_size(op, argtypes));
}
