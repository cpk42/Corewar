/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 21:25:08 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/28 21:32:23 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int do_zjmp(t_proc *ps)
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
	if (ps->carry)
		return (args[0] % IDX_MOD);
	else
		return (1);
}
