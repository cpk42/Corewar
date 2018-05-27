/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:34:51 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 14:26:24 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static void			add_two_ones(void)
{
	QUICK_INIT_TEST_WITH_PS("test/add/champ_add.cor");
	ps->regs[1] = 1;
	ps->regs[2] = 1;
	ps->regs[3] = 1;
	ps->carry = 1;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(ps->regs[3] == 2);
	assert(ps->carry == 0);
}

static void			add_one_and_minusone(void)
{
	QUICK_INIT_TEST_WITH_PS("test/add/champ_add.cor");
	assert(ps->carry == 0);
	ps->regs[1] = -1;
	ps->regs[2] = 1;
	ps->regs[3] = 90;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(ps->regs[3] == 0);
	assert(ps->carry == 1);
}

void				test_add(void)
{
	add_two_ones();
	add_one_and_minusone();
}
