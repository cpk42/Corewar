/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:21:08 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/24 14:31:46 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				print_player(int player_num)
{
	unsigned int	k;

	player_num--;
	printf("Magic:\t\t\t[ %x ]\nPlayer %d:\t\t[ %s ]\nProg_size:\t\t[ %u ]\nComment:\t\t[ %s ]\n\n", g_vm.p[player_num].h.magic, (int)g_vm.p[player_num].id, g_vm.p[player_num].h.prog_name, g_vm.p[player_num].h.prog_size, g_vm.p[player_num].h.comment);
	k = -1;
	while (++k < g_vm.p[player_num].h.prog_size)
	{
		printf("%2.2hhx ", g_vm.p[player_num].code[k]);
		if ((k % 16) == 15 && k)
			printf("\n");
	}
	printf("\n\n");
}

void				print_arena(void)
{
	int				k;

	k = -1;
	while (++k < MEM_SIZE)
	{
		printf("%2.2hhx ", g_arena[k]);
		if ((k % 64) == 63 && k)
			printf("\n");
	}
}
