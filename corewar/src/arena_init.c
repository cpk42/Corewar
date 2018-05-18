/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:59:22 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/17 06:48:00 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** This function takes (argc - 1, argv + 1)
*/

void				initialize_arena(int ac, char **av)
{
	int				i;
	t_proc			*p;
	header_t		*header;
	char			buf[MEM_SIZE];

	ft_bzero(buf, MEM_SIZE);
	i = -1;
	while (++i < ac)
	{
		scrape_player_header(
	}
}
