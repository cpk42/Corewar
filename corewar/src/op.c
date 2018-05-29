/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/05/28 19:37:42 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static int		not_implemented(t_proc *ps)
{
	printf("Error: operation not yet implemented. Did you remember to add it to src/op.c?\n");
	ps = NULL;
	exit(1);
}

t_op	g_op_tab[17] =
{
	{not_implemented, "live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{do_ld, "ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{do_st, "st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{do_add, "add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{do_sub, "sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{do_and, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, "et (and r1, r2, r3 r1&r2 -> r3", 1, 0},
	{do_or, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, "ou (or r1, r2, r3 r1 | r2 -> r3", 1, 0},
	{do_xor, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{not_implemented, "zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{not_implemented, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, "load index", 1, 1},
	{do_sti, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "store index", 1, 1},
	{not_implemented, "fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{not_implemented, "lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{not_implemented, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, "long load index", 1, 1},
	{not_implemented, "lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{not_implemented, "aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, 0, {0}, 0, 0, 0, 0, 0}
};
