/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 06:56:55 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/19 06:40:12 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		write_to_arena(int index, void *src, unsigned int size)
{
	endian_swap((char *)src, size);
	ft_memcpy((g_arena + index), src, size);
}

void		read_from_arena(int index, void *dst, unsigned int size)
{
	ft_memcpy(dst, (g_arena + index), size);
	endian_swap((char *)dst, size);
}
