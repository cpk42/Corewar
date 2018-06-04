/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:34:56 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:06:59 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static int writeme = -91462;
static int offset1 = 81;
static int offset2 = -19;

static void quick_test_local(int r3, int r4, char *argtypes)
{
	t_proc *ps = quick_test_setup("sti", argtypes, writeme, r3, r4);
	assert(get_int(ps, offset1 + offset2) == writeme);
}
void				test_sti(void)
{
	quick_test_local(offset1, offset2, "rrr");
	quick_test_local(offset1, WHATEVER, "rrd");
	quick_test_local(WHATEVER, WHATEVER, "rdd");
	quick_test_local(offset2, WHATEVER, "rir");
	quick_test_local(offset2, WHATEVER, "rdr");
	quick_test_local(offset2, WHATEVER, "rid");
}
