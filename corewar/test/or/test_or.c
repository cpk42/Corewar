/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 01:24:57 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/29 01:29:56 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static int orme = 912329;
static int orme2 = -192772;
static int expected = 912329 & -192772;

static void			quick_test_local(char *argtypes, int r2, int r3)
{
	t_proc *ps = quick_test_setup("or", argtypes, r2, r3, WHATEVER);
	assert(ps->regs[3] = expected);
}

static void			test_sets_carry(void)
{
	t_proc *ps = quick_test_setup("or", "rrr", 0x0, 0x0, WHATEVER);
	assert(ps->regs[3] == 0 && ps->carry == 1);
	ps->regs[2] = 0xFFFFFFFF;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(ps->regs[3] != 0 && ps->carry == 0);
}

void				test_or(void)
{
	quick_test_local("rrr", orme, orme2);
	quick_test_local("iir", WHATEVER, WHATEVER);
	test_sets_carry();
}
