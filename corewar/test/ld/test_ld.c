/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:39:42 by jgelbard          #+#    #+#             */
/*   Updated: 2018/06/06 13:12:22 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

#define PROBLEM 0xd0000102
void				test_ld(void)
{
	t_proc *ps;
	ps = quick_test_setup("ld", "drx", WHATEVER, WHATEVER, WHATEVER);
	assert(ps->regs[1] == 9190);
	ps = quick_test_setup("ld", "irx", WHATEVER, WHATEVER, WHATEVER);
	long res = PROBLEM;
	assert(!ft_memcmp(ps->regs + 1, &res, 4));
}
