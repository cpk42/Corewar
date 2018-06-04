/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:34:51 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:07:04 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static void			add_two_ones(void)
{
	t_proc *ps = quick_test_setup("add", "rrr", 1, 1, WHATEVER);
	assert(ps->regs[3] == 2);
	assert(ps->carry == 0);
}

static void			add_one_and_minusone(void)
{
	t_proc *ps = quick_test_setup("add", "rrr", -1, 1, WHATEVER);
	assert(ps->regs[3] == 0);
	assert(ps->carry == 1);
}


void				test_add(void)
{
	add_two_ones();
	add_one_and_minusone();
}
