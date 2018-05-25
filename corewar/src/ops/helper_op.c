/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 21:36:09 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/24 23:03:49 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		fetch_args(t_arg_type *argtypes, t_proc *ps, int *arr)
{
	int		ind_offset;
	int		i;
	int		x;

	i = 2;
	x = -1;
	while (++x < 3)
	{
		if (argtypes[x] == T_REG)
		{
			arr[x] = x == 2 ? get_byte(ps, i) : ps->regs[get_byte(ps, i) - 1];
			i++;
		}
		else if (argtypes[x] == T_DIR)
		{
			arr[x] = get_int(ps, i);
			i += DIR_SIZE;
		}
		else if (argtypes[x] == T_IND)
		{
			ind_offset = follow_indirect_reference(ps, i);
			arr[x] = ind_offset;
			i += IND_SIZE;
		}
	}
}
