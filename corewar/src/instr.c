/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:53:16 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/23 22:33:55 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** The coding byte consists of two-bit pairs, one for each argument, which
** indicate how the argument at that index is to be read.
** E.g. 10110000 == [DIR_CODE, IND_CODE] if DIR_CODE is 2 and IND_CODE is 3.
** Immediately follows opcode. Not present on live, zjmp, fork, or lfork.
*/

/*
** Get each two-bit pair from the coding byte and translate it to the type
** of argument it represents (11 == IND_CODE -> T_IND). Return a static array.
** This ignores T_LAB, but I don't know what that is yet. Change later.
*/

t_arg_type	*extract_argtypes(byte coding_byte)
{
	static t_arg_type	argtypes[MAX_ARGS_NUMBER];
	int					mask;
	int					i;
	int					code;

	ft_bzero(argtypes, MAX_ARGS_NUMBER);
	mask = 0x3;
	i = MAX_ARGS_NUMBER - 1;
	while (i >= 0)
	{
		code = coding_byte & mask;
		if (code == 0)
			argtypes[i] = 0;
		else if (code == REG_CODE)
			argtypes[i] = T_REG;
		else if (code == DIR_CODE)
			argtypes[i] = T_DIR;
		else if (code == IND_CODE)
			argtypes[i] = T_IND;
		else
			return (NULL);
		coding_byte >>= 2;
		--i;
	}
	return ((t_arg_type *)argtypes);
}

int			has_legal_argtypes(int opcode, t_arg_type *argtypes)
{
	int		i;
	t_op	op;

	op = g_op_tab[opcode - 1];

	if (!argtypes)
		return (0);
	i = 0;
	while (i < op.argc)
	{
		if (!(argtypes[i] & op.legal_argtypes[i]))
			return (0);
		++i;
	}
	while (i < MAX_ARGS_NUMBER)
	{
		if (argtypes[i])
			return (0);
		++i;
	}
	return (1);
}

int			instr_size(int opcode, t_arg_type *argtypes)
{
	int			size;
	t_op		op;
	int			i;

	size = 0;
	op = g_op_tab[opcode - 1];
	i = 0;
	while (i < op.argc)
	{
		if (argtypes[i] == T_REG)
			size += 1;
		else if (argtypes[i] == T_IND)
			size += IND_SIZE;
		else if (argtypes[i] == T_DIR)
			size += DIR_SIZE;
		++i;
	}
	return (size);
}
