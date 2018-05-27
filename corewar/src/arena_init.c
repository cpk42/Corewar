/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:59:22 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/27 15:46:49 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Simple error function. Prints error message and exits.
*/

void				init_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

/*
** This function takes (argc - 1, argv + 1)
*/

void				initialize_arena(char **p_names)
{
	int				i;
	t_proc			*tmp_proc;

	i = -1;
	g_vm.proc_head = new_proc(0, NULL);
	tmp_proc = g_vm.proc_head;
	while (++i < g_vm.player_num)
	{
		new_player(p_names[i], &g_vm.p[i]);
		g_vm.p[i].start_idx = (MEM_SIZE / g_vm.player_num) * i;
		ft_memcpy((void *)(g_arena + g_vm.p[i].start_idx),
				(void *)g_vm.p[i].code, g_vm.p[i].h.prog_size);
		add_proc(g_vm.p[i].start_idx, NULL);
		g_vm.proc_head->regs[1] = ~(i + 1);
	}
	del_proc(&tmp_proc);
}
