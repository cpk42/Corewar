/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 20:22:05 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include "arena.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> //printf

# define ft_abs(x) ((x) < 0 ? -(x) : (x))

/*
** WIP struct for players.
*/

typedef struct		s_player
{
	header_t			h;
	char				id;
	int					start_idx;
	char				code[CHAMP_MAX_SIZE];
	int					cycle_lived;
}					t_player;

/*
** Player functions.
*/

void				new_player(char *file_name, t_player *p);
void				del_player(t_player **p);

/*
** WIP struct for proccesses.
*/

typedef struct		s_proc
{
	int					proc_id;
	int					pc;
	int					lcount;
	int					tminus;
	long				regs[REG_NUMBER];
	struct s_proc		*next;
	struct s_proc		*prev;
}					t_proc;

/*
** t_proc functions:
*/

t_proc				*new_proc(int mem_idx, t_proc *parent);
void				del_proc(t_proc **p);
void				add_proc(int mem_idx, t_proc *parent);

/*
** Global declaration for g_vm.
*/

typedef struct		s_vm
{
	int					player_num;
	t_player			p[MAX_PLAYERS];
	int					proc_num;
	t_proc				*proc_head;
	int					cycle;
}					t_vm;

t_vm				g_vm;

void				initialize_vm(int player_num);

#endif
