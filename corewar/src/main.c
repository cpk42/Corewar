/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 20:31:43 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			usage(void)
{
	ft_putendl("Ya dun goofed.");
}

int			main(int argc, char **argv)
{
	ft_putendl("Hello Corewar!");
	if (argc - 1 >= 1 && argc - 1 <= MAX_PLAYERS)
	{
		initialize_vm(argc - 1);
		initialize_arena(argv + 1);
	}
	else
		usage();
	return (0);
}
