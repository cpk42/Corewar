/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:39:21 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/21 23:11:33 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** For getting an actual number out of a string of bytes. We can't just read
** the memory and cast to (int) or (short) because the endianness will be wrong.
*/

unsigned long	bigendian_num(byte *buf, size_t size)
{
	unsigned long res;
	unsigned long x;

	res = 0;
	while (size > 0)
	{
		x = (unsigned long)(*buf);
		x = x << ((size - 1) * 8);
		res |= x;
		--size;
		++buf;
	}
	return (res);
}

#ifdef DEBUG
# include <stdio.h>
/* Does what it says on the tin. Useful for debugging. `printf' is illegal,
** though; hence the flag.
*/

void		print_bytes(void *p, int size)
{
	byte	*b;
	int		i;

	b = (byte *)p;
	printf("%02X", *b);
	--size;
	++b;
	i = 1;
	while (size > 0)
	{
		if (!(i % 4))
			printf(" ");
		else
			printf(":");
		printf("%02X", *b);
		++b;
		--size;
		++i;
	}
	printf("\n");
}

#endif
