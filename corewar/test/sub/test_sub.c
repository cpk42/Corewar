/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:28:08 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:33:52 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static void			sub_two_from_two(void)
{
	t_proc *ps = quick_test_setup("sub", "rrr", 2, 2, WHATEVER);
	assert(ps->regs[3] == 0);
	assert(ps->carry == 1);
}

static void			sub_three_from_two(void)
{
	t_proc *ps = quick_test_setup("sub", "rrr", 2, 3, WHATEVER);
	assert(ps->regs[3] == -1);
	assert(ps->carry == 0);
}

void				test_sub(void)
{
	sub_two_from_two();
	sub_three_from_two();
}
