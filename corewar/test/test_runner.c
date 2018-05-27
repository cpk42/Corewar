/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:34:07 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 14:44:54 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_test.h"

static void			run_test(char *test_name)
{
	DEFINE_TEST(add);
	DEFINE_TEST(st);
	DEFINE_TEST(sti);
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
