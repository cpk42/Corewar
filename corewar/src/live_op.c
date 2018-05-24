/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 22:08:24 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 22:13:31 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			do_live(t_proc *p)
{
	int			p_id;

	vm_read(p->pc, p->pc + 1, &p_id, DIR_SIZE);
	p_id = ~p_id - 1;
	g_vm.p[p_id].cycle_lived = g_vm.cycle;
	p->lcount++;
}
