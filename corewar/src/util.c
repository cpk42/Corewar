/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:39:21 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/23 22:58:16 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** For getting an actual number out of a string of bytes. We can't just read
** the memory and cast to (int) or (short) because the endianness will be wrong.
*/

unsigned long	bigendian_num(char *buf, size_t size)
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

void		print_argtypes(t_arg_type *argtypes)
{
	for (int i = 0; i < 4; i++)
	{
		int t = argtypes[i];
		char *s = t == T_DIR ? "T_DIR" : t == T_REG ? "T_REG" : t == T_IND ? "T_IND" : t == T_LAB ? "T_LAB" : t == 0 ? "--" : "ERR?";
		printf("%s%s", s, i == 3 ? "\n" : ", ");
	}
}

void		print_bytes(void *p, int size)
{
	char	*b;
	int		i;

	b = (char *)p;
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
		printf("%02hhX", *b);
		++b;
		--size;
		++i;
	}
	printf("\n");
}

#endif
