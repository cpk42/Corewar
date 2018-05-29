/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:35:01 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:38:32 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static int xorme = 912329;
static int xorme2 = -192772;
static int expected = 912329 ^ -192772;

static void			quick_test_local(char *argtypes, int r2, int r3)
{
	t_proc *ps = quick_test_setup("xor", argtypes, r2, r3, WHATEVER);
	assert(ps->regs[3] = expected);
}

static void			test_sets_carry(void)
{
	t_proc *ps = quick_test_setup("xor", "rrr", 0xFFFFFFFF, 0xFFFFFFFF, WHATEVER);
	assert(ps->regs[3] == 0 && ps->carry == 1);
	ps->regs[2] = 9;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(ps->regs[3] != 0 && ps->carry == 0);
}

void				test_xor(void)
{
	quick_test_local("rrr", xorme, xorme2);
	test_sets_carry();
}
