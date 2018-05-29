/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:57:20 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:15:08 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static int andme = 912329;
static int andme2 = -192772;
static int expected = 912329 & -192772;

static void			quick_test_local(char *argtypes, int r2, int r3)
{
	t_proc *ps = quick_test_setup("and", argtypes, r2, r3, WHATEVER);
	assert(ps->regs[3] = expected);
}

static void			test_sets_carry(void)
{
	t_proc *ps = quick_test_setup("and", "rrr", 0xFF00FF00, 0x00FF00FF, WHATEVER);
	assert(ps->regs[3] == 0 && ps->carry == 1);
	ps->regs[2] = 0xFFFFFFFF;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(ps->regs[3] != 0 && ps->carry == 0);
}

void				test_and(void)
{
	quick_test_local("rrr", andme, andme2);
	quick_test_local("iir", WHATEVER, WHATEVER);
	test_sets_carry();
}

