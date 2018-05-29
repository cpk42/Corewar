/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:37:45 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 18:58:08 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_TEST_H
# define COREWAR_TEST_H
# define DEFINE_TEST(opname) if (!ft_strcmp(test_name, #opname)) {test_ ## opname (); puts("----passed test: " #opname); }
# include "corewar.h"
# define WHATEVER 12345
# define QUICK_INIT_TEST_WITH_PS(comma_separated_champ_path_strings) \
	char *_champ_paths[] = { comma_separated_champ_path_strings }; \
	int _numchamps = sizeof(_champ_paths) / sizeof(*_champ_paths); \
	initialize_vm( _numchamps ); \
	ft_bzero(g_arena, MEM_SIZE); \
	initialize_arena( _champ_paths ); \
	t_proc *ps = new_proc(0, 0);

t_proc		*quick_test_setup(char *opname, char *argtypes, int r2, int r3, int r4);
void		test_add(void);
void		test_st(void);
void		test_sti(void);
void		test_and(void);
#endif
