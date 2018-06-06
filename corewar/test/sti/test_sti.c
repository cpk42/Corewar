/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:34:56 by jgelbard          #+#    #+#             */
/*   Updated: 2018/06/06 12:00:17 by jgelbard         ###   ########.fr       */
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
	int res = get_int(ps, offset1 + offset2);
	assert(!ft_memcmp(&res, &writeme, 4));
}
void				test_sti2(void)
{
	quick_test_local(offset1, offset2, "rrr");
	quick_test_local(offset1, WHATEVER, "rrd");
	quick_test_local(WHATEVER, WHATEVER, "rdd");
	quick_test_local(offset2, WHATEVER, "rir");
	quick_test_local(offset2, WHATEVER, "rdr");
	quick_test_local(offset2, WHATEVER, "rid");
}

void test_sti() {
	writeme = -91462;
	test_sti2();
	writeme =0;
	test_sti2();
	writeme=9;
	test_sti2();
	writeme=INT_MAX;
	test_sti2();
	writeme=INT_MIN;
	test_sti2();
}
