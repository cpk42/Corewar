/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:21:33 by mmoros            #+#    #+#             */
/*   Updated: 2018/05/24 22:30:20 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		iter_procs(t_proc *proc)
{
	while (proc)
	{
		if (proc->tminus)
			proc->tminus--;
		else if (g_arena[proc->pc] < 17 && g_arena[proc->pc] > 0)
			proc->pc += g_op_tab[proc->pc].op(proc);
		else
			proc->pc++;
		proc = proc->next;
	}
}

static void		executioner(t_proc *proc, int *foun_of_youth)
{
	int		mercy_count;
	t_proc	*tmp;

	mercy_count = 0;
	while (proc)
	{
		tmp = proc->next;
		if (proc->lcount)
		{
			mercy_count += proc->lcount;
			proc->lcount = 0;
		}
		else
			del_proc(proc);
		proc = tmp;
	}
	if (mercy_count > NBR_LIVE)
		*foun_of_youth -= CYCLE_DELTA;
	if (++g_vm.alive_checks % MAX_CHECKS == 0)
		*foun_of_youth -= CYCLE_DELTA;
	g_vm.dminus += *foun_of_youth;
}

static void		give_out_candy(void)
{
	ft_printf("Player X (champion_name) won\n"); //check for last live player
	ft_printf("\nGAME OVER\n\n");
}

void			processor(void)
{
	int		foun_of_youth;

	foun_of_youth = CYCLE_TO_DIE;
	g_vm.dminus = foun_of_youth;
	while (g_vm.proc_head)
	{
		g_vm.cycle++;
		iter_procs(g_vm.proc_head);
		if (g_vm.cycle >= g_vm.dminus)
			executioner(g_vm.proc_head, &foun_of_youth);
	}
	give_out_candy();
}
