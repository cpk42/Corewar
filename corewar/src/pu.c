/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:21:33 by mmoros            #+#    #+#             */
/*   Updated: 2018/05/24 14:20:32 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	alive(t_proc *procs, int *d_minus)
{
	int		pulse_count;

	if (g_vm.cycle < g_vm.dminus)
		return (1);
	pulse_count = 0;
	while (procs)
	{
		if (procs->lcount > 0)
		{
			pulse_count++;
			procs->lcount = 0;	
		}
		else
			del_proc(procs);
		procs = procs->next;
	}
	g_vm.alive_checks++;
	if (pulse_count > NBR_LIVE || g_vm.alive_checks == MAX_CHECKS)
	{
		g_vm.alive_checks %= MAX_CHECKS;
		
	}

}

void		processor()
{
	while (alive())
	{
		
	}
}
