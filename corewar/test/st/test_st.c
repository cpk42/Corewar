/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:08:38 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:24:11 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static void		test_with_reg_and_indirect(void)
{
	t_proc *ps = quick_test_setup("st", "rix", 0x66666666, WHATEVER, WHATEVER);
	assert(get_int(ps, 10) == 0x66666666);
}

static void		test_with_two_registers(void)
{
	t_proc *ps = quick_test_setup("st", "rrx", 0x66, 90, WHATEVER);
	assert(ps->regs[2] == ps->regs[1]);
}


void		test_st(void)
{
	test_with_reg_and_indirect();
	test_with_two_registers();
}
