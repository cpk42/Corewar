/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/17 02:21:35 by ltanenba         ###   ########.fr       */
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
	if (argc > 2 && argc < 6)
	{
		initialize_arena(argc - 1, argv + 1);
	}
	else
		usage();

	argc = 0;
	argv = 0;
	return (0);
}
