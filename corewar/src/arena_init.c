/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:59:22 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/18 10:44:50 by ltanenba         ###   ########.fr       */
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

void				init_vars(void)
{
	g_arena = &g_ARENA_MEMORY[0];
}

/*
** This function takes (argc - 1, argv + 1)
*/

void				initialize_arena(int ac, char **av)
{
	int				i;
	unsigned int	k;
	t_player		*p;

	init_vars();
	i = -1;
	while (++i < ac)
	{
		p = new_player(av[i]);
		printf("Magic:\t\t\t[ %x ]\nPlayer %d:\t\t[ %s ]\nProg_size:\t\t[ %u ]\nComment:\t\t[ %s ]\n\n", p->h.magic, (int)p->id, p->h.prog_name, p->h.prog_size, p->h.comment);
		k = -1;
		while (++k < p->h.prog_size)
			printf("%2.2x ", p->code[k]);
		printf("\n\n");
	}
}
