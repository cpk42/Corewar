/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:08:38 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 14:26:35 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static void		test_with_reg_and_indirect(void)
{
	QUICK_INIT_TEST_WITH_PS("test/st/champ_st_reg_ind.cor");
	ps->regs[1] = 0x66666666;
	ps->carry = 1;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(get_int(ps, 10) == 0x66666666);
	assert(ps->carry == 1);
}

static void		test_with_two_registers(void)
{
	QUICK_INIT_TEST_WITH_PS("test/st/champ_st_reg_reg.cor");
	ps->regs[2] = 90;
	ps->regs[1] = 0x66;
	ps->carry = 1;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(ps->regs[2] == ps->regs[1]);
	assert(ps->carry == 1);
}


void		test_st(void)
{
	test_with_reg_and_indirect();
	test_with_two_registers();
}
