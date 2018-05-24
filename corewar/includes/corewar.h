/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 21:55:23 by jgelbard         ###   ########.fr       */
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
# include "libft.h"
# include <stdlib.h>
# include <string.h>

# define MAX_OPCODE 16
# define TRUNCATED_DIR_SIZE IND_SIZE

/*
** Always `MEMSAFE' memory accesses to make sure we don't exceed our boundaries.
*/
# define MEMSAFE(idx) (idx % MEM_SIZE)

/*
** Usually `LEASH', too, depending on the operation. IDX_MOD limits processes
** to operating within a certain range. We won't leash on lld, lldi or lfork.
*/
# define LEASH(idx, pc) (pc + (idx % IDX_MOD))

# define OP_ST 0x03
# define OP_STI 0x0B

typedef unsigned char	byte;

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

typedef struct			s_proc
{
	int		pc;
	int		regs[REG_NUMBER + 1];
	int		carry;
}						t_proc;

extern t_op				g_op_tab[17];

byte		*read_from_arena(byte *ar, size_t size, int pc);
byte		*lread_from_arena(byte *ar, size_t size, int pc);

void		reg_mem_write(byte *ar, t_proc *ps, int reg_idx, int dst_idx);
void		lreg_mem_write(byte *ar, t_proc *ps, int reg_idx, int dst_idx);

void		print_bytes(void *p, int size);
void		print_argtypes(t_arg_type *argtypes);
unsigned long	bigendian_num(byte *buf, size_t size);
t_arg_type	*extract_argtypes(byte coding_byte);
int			has_legal_argtypes(int opcode, t_arg_type *argtypes);
int		instr_size(int opcode, t_arg_type *argtypes);

/* ops */
int			do_st(byte *ar, t_proc *ps);
int			do_sti(byte *ar, t_proc *ps);

#endif
