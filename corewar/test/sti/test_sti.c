/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:34:56 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 16:53:27 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static int writeme = -91462;
static int offset1 = 81;
static int offset2 = -19;
#define UNUSED 12345
static void			run_test_after_setting_r3_r4_and_argtypes(int r3, int r4, char *arg_types)
{
	char *path = ft_strdup("test/sti/champ_sti_xxx.cor");
	int argidx = strlen(path) - strlen("xxx.cor");
	path[argidx++] = *arg_types++;
	path[argidx++] = *arg_types++;
	path[argidx++] = *arg_types++;
	QUICK_INIT_TEST_WITH_PS(path);
	ps->regs[1] = writeme;
	ps->regs[2] = r3;
	ps->regs[3] = r4;
	PROCESS_CURRENT_OP(ps)->op(ps);
	assert(get_int(ps, offset1 + offset2) == writeme);
}

void				test_sti(void)
{
	run_test_after_setting_r3_r4_and_argtypes(offset1, offset2, "rrr");
	run_test_after_setting_r3_r4_and_argtypes(offset1, UNUSED, "rrd");
	run_test_after_setting_r3_r4_and_argtypes(UNUSED, UNUSED, "rdd");
	run_test_after_setting_r3_r4_and_argtypes(offset2, UNUSED, "rir");
	run_test_after_setting_r3_r4_and_argtypes(offset2, UNUSED, "rdr");
	run_test_after_setting_r3_r4_and_argtypes(offset2, UNUSED, "rid");
}
