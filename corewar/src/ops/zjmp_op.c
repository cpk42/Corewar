/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 21:25:08 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/29 17:13:25 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int do_zjmp(t_proc *ps)
{
	t_arg_type	*argtypes;
	t_op		*op;

	ft_bzero(args, 4);
	op = PROCESS_CURRENT_OP(ps);
	argtypes = extract_argtypes(get_byte(ps, 1));
	if (!has_legal_argtypes(op, argtypes))
		return (2);
	if (ps->carry)
		return (args[0] % IDX_MOD);
	else
		return (0);
}
