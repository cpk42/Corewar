/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:34:07 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 19:43:20 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

t_proc				*quick_test_setup(char *opname, char *argtypes, int r2, int r3, int r4)
{
	char *path = ft_strnew(200);
	ft_strcat(path, "test/");
	ft_strcat(path, opname);
	ft_strcat(path, "/champ_");
	ft_strcat(path, opname);
	ft_strcat(path, "_");
	ft_strcat(path, argtypes);
	ft_strcat(path, ".cor");
	QUICK_INIT_TEST_WITH_PS(path);
	ps->regs[1] = r2;
	ps->regs[2] = r3;
	ps->regs[3] = r4;
	PROCESS_CURRENT_OP(ps)->op(ps);
	return (ps);
}

static void			run_test(char *test_name)
{
	DEFINE_TEST(add);
	DEFINE_TEST(st);
	DEFINE_TEST(sti);
	DEFINE_TEST(and);
	DEFINE_TEST(sub);
	DEFINE_TEST(xor);
	DEFINE_TEST(ld);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		puts("Name one or more ops, like `./tcore add st`");
		return (1);
	}
	printf("running tests: ");
	for (int i = 1; i < argc; i++)
		printf("%s%s", argv[i], i == argc - 1 ? "\n" : ", ");
	for (int i = 1; i < argc; i++)
		run_test(argv[i]);
	return (0);
}
