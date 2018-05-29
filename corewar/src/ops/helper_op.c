/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 21:36:09 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/28 19:53:08 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		fetch_args(t_op *op, t_arg_type *argtypes, t_proc *ps, int *arr)
{
	int		ind_offset;
	int		i;
	int		x;

	i = 2;
	x = -1;
	while (++x < 3)
	{
		if (argtypes[x] == T_REG)
			arr[x] = x == 2 ? get_byte(ps, i) : ps->regs[get_byte(ps, i) - 1];
		else if (argtypes[x] == T_DIR)
			arr[x] = op->truncate ? get_short(ps, i) : get_int(ps, i);
		else if (argtypes[x] == T_IND)
		{
			ind_offset = READ_IND(op->opcode) ? short_indirect_reference(ps, i)
				: follow_indirect_reference(ps, i);
			arr[x] = ind_offset;
		}
		if (argtypes[x] == T_DIR || argtypes[x] == T_IND)
			i += ((argtypes[x] == T_DIR && !op->truncate) ? DIR_SIZE : IND_SIZE);
		else
			i++;
	}
}

int		short_indirect_reference(t_proc *ps, int idx_of_indirect)
{
	short	ind;
	short	ret;

	ind = get_short(ps, idx_of_indirect);
	ret = get_short(ps, ind);
	return (ret);
}
