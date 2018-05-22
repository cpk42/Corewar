/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/22 16:50:34 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corewar.h"

void		do_st(byte *ar, t_proc *ps, int idx);

void		read_instr(byte *ar, int idx, t_proc *ps)
{
	byte		opcode;
	t_op		op;

	if((opcode = ar[0]) < 1 || opcode > MAX_OPCODE)
		return ;
	op = g_op_tab[opcode - 1];
	if (op.has_codebyte == 1 && !has_legal_argtypes(ar[1], &op))
		return ;
	if (op.opcode == OP_ST)
		do_st(ar, ps, idx);
}

void		do_st(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
	if (argtypes[1] == T_REG)
	{
		reg_reg_write(ps, bytes[3], bytes[2]);
	}
	else // already checked for errors, right?
	{
		ind_offset = bigendian_num(bytes + 3, IND_SIZE);
		reg_mem_write(ps, ind_offset, bytes[2], ar);
	}
}

int	main(void)
{
	byte	*mem = calloc(900, 1);
	t_proc	*ps = malloc(sizeof(*ps));

	ps->pc = 0;
	ft_bzero(ps->regs, sizeof(ps->regs));
	ps->regs[2] = 0xAABBCCDD;

	mem[0] = 0x03; // OP_ST
	mem[1] = 0x70; // argcodes: 10110000 == T_REG, T_IND
	mem[2] = 0x02; // reg == r2
	mem[3] = 0x00; // ind offset = 0 ...
	mem[4] = 0x0a; // ... + 10
	// so: write the value 0xAABBCCDD at idx offset 10
	// ie, 11 bytes in front of this position
	puts("BEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, 0, ps);
	puts("AFTER:");
	print_bytes(mem, 20);
	return (0);
}
