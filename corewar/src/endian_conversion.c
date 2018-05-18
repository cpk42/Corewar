/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 06:00:45 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/17 06:11:23 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			swap_endianness(char *mem, int size)
{
	int			i;

	i = -i;
	while (++i < size / 2)
	{
		mem[i]				= mem[i] ^ mem[size - 1 - i];
		mem[size - 1 - i]	= mem[i] ^ mem[size - 1 - i];
		mem[i]				= mem[i] ^ mem[size - 1 - i];
	}
}
