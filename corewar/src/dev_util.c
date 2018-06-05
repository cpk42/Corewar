/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:33:09 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/24 14:33:10 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	int		i;

	i = 0;
	while (i < size)
	{
		if (i > 0)
			printf("%s", i % 4 == 0 ? " " : ":");
		printf("%02hhX", ((unsigned char *)p)[i]);
		++i;
	}
	printf("\n");
}

void		print_registers(t_proc *ps)
{
	printf("registers: ");
	for (int i = 0; i < REG_NUMBER; i++)
	{
		printf("%d%s", (int)(ps->regs[i]), i == REG_NUMBER - 1 ? "\n" : ", ");
	}
}

void		print_registers_bytes(t_proc *ps)
{
	printf("registers:\n");
	for (int i = 0; i < REG_NUMBER; i++)
	{
		printf("%d: ", i);
		print_bytes(ps->regs + i, sizeof(ps->regs[i]));
	}
}

#endif
