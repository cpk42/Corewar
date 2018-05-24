/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:07:16 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 21:25:42 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		initialize_vm(int player_num)
{
	g_vm.player_num = player_num;
	g_vm.proc_num = 0;
	g_vm.cycle = 0;
	g_vm.dminus = 0;
	g_arena = &g_ARENA_MEMORY[0];
}
