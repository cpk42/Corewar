/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:21:33 by mmoros            #+#    #+#             */
/*   Updated: 2018/05/23 21:25:49 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	alive(t_proc *procs, int *d_minus)
{
	int		life_count;

	life_count = 0;
	while (procs)
	{
		if (procs->lcount > 0)
		{
			life_count += procs->lcount;
			procs->lcount = 0;
			
		}
		else
			del_proc(procs);
		procs = procs->next;
	}

}

void		processor(byte *ar, t_proc *procs)
{
	int		d_minus;

	d_minus = CYCLE_TO_DIE;
	while (alive(procs, &d_minus))
	{
		
	}
}
