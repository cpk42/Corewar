/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/21 23:42:34 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"

# define MAX_OPCODE 16

/*
** The coding byte consists of two-bit pairs, one for each argument, which
** indicate how the argument at that index is to be read.
** E.g. 10110000 == [DIR_CODE, IND_CODE] if DIR_CODE is 2 and IND_CODE is 3.
** Immediately follows opcode. Not present on live, zjmp, fork, or lfork.
*/
# define ARG_CODE(coding_byte, arg_idx) ((coding_byte >> ((3 - arg_idx) * 2) & 3))

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
	int		legal_argcodes[4];
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

extern t_op				op_tab[17];


byte		*read_from_arena(byte *ar, int start_idx, size_t size, int pc);
void		write_to_arena(byte *ar, int start_idx, size_t size, int pc, void *bytes);
void		write_backwards(byte *ar, int idx, size_t size, int pc, void *bytes);
void		reg_reg_write(t_proc *ps, int dst_reg, int src_reg);
void		reg_mem_write(t_proc *ps, int dst_idx, int src_reg, byte *ar);
void		print_bytes(void *p, int size);
unsigned long	bigendian_num(byte *buf, size_t size);

#endif

#ifndef DEBUG
# define DEBUG

#endif
