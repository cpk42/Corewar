/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/24 23:18:05 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG // XXX
#ifdef DEBUG
# include <stdio.h>
# include <assert.h>
#endif

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"

typedef struct		s_proc
{
	int					carry;
	int					proc_id;
	int					pc;
	int					lcount;
	int					tminus;
	long				regs[REG_NUMBER];
	struct s_proc		*next;
	struct s_proc		*prev;
}					t_proc;


# include "arena.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MAX_OPCODE 16
# define PROCESS_CURRENT_OP(ps) (g_op_tab + ((int)(g_arena[ps->pc]) - 1))
# define TRUNCATED_DIR_SIZE IND_SIZE
# define ft_abs(x) ((x) < 0 ? -(x) : (x))

enum	e_opcodes
{
	LIVE = 1,
	LD, 
	ST, 
	ADD,
	SUB,
	AND,
	OR, 
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
};

typedef struct			s_op
{
	char	*name;
	int		argc;
	int		legal_argtypes[4];
	int		opcode;
	int		cycle_cost;
	char	*mnemonic;
	int		has_codebyte;
	int		truncate;
}					t_op;

extern t_op				g_op_tab[17];

int			get_byte(t_proc *ps, int req_idx);
int			get_short(t_proc *ps, int req_idx);
int			get_int(t_proc *ps, int req_idx);
void		print_bytes(void *p, int size);
void		print_argtypes(t_arg_type *argtypes);
void		print_registers(t_proc *ps);
t_arg_type	*extract_argtypes(char coding_byte);
int			has_legal_argtypes(t_op *op, t_arg_type *argtypes);
int			instr_size(t_op *op, t_arg_type *argtypes);

/* ops */
int			do_st(t_proc *ps);
int			do_sti(t_proc *ps);

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
	int					lcount;
}					t_player;

/*
** Player functions.
*/

void				new_player(char *file_name, t_player *p);
void				del_player(t_player **p);

/*
** WIP struct for proccesses.
*/

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
	int					dminus;
}					t_vm;

t_vm				g_vm;

void				initialize_vm(int player_num);
void				print_arena(void);
void				print_player(int player_num);

#endif
