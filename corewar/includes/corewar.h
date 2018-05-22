/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/22 16:49:06 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG // XXX
#ifdef DEBUG
# include <stdio.h>
#endif

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"

# define MAX_OPCODE 16

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
	int		changes_carry;
}					t_op;

typedef struct			s_proc
{
	int		pc;
	int		regs[REG_NUMBER];
}						t_proc;

extern t_op				g_op_tab[17];


byte		*read_from_arena(byte *ar, int start_idx, size_t size, int pc);
void		write_to_arena(byte *ar, int start_idx, size_t size, int pc, void *bytes);
void		write_backwards(byte *ar, int idx, size_t size, int pc, void *bytes);
void		reg_reg_write(t_proc *ps, int dst_reg, int src_reg);
void		reg_mem_write(t_proc *ps, int dst_idx, int src_reg, byte *ar);
void		print_bytes(void *p, int size);
unsigned long	bigendian_num(byte *buf, size_t size);
t_arg_type	*extract_argtypes(byte coding_byte);
int			has_legal_argtypes(byte coding_byte, t_op *op);

#endif
