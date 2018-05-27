/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:37:45 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 14:58:53 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_TEST_H
# define COREWAR_TEST_H
# define DEFINE_TEST(opname) if (!ft_strcmp(test_name, #opname)) {test_ ## opname (); puts("----passed test: " #opname); }
# include "corewar.h"
# define QUICK_INIT_TEST_WITH_PS(comma_separated_champ_path_strings) \
	char *_champ_paths[] = { comma_separated_champ_path_strings }; \
	int _numchamps = sizeof(_champ_paths) / sizeof(*_champ_paths); \
	initialize_vm( _numchamps ); \
	ft_bzero(g_arena, MEM_SIZE); \
	initialize_arena( _champ_paths ); \
	t_proc *ps = new_proc(0, 0);

void		test_add(void);
void		test_st(void);
void		test_sti(void);
#endif
