/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 06:00:45 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/18 10:19:26 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			endian_swap(char *mem, int size)
{
	int			i;

	i = -1;
	while (++i < size / 2)
	{
		mem[i]				= mem[i] ^ mem[size - 1 - i];
		mem[size - 1 - i]	= mem[i] ^ mem[size - 1 - i];
		mem[i]				= mem[i] ^ mem[size - 1 - i];
	}
}
