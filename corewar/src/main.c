/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/22 21:45:58 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		do_st(byte *ar, t_proc *ps, int idx);
void		do_ld(byte *ar, t_proc *ps, int idx);

void		read_instr(byte *ar, int idx, t_proc *ps)
{
	byte		opcode;
	t_op		op;

	if((opcode = ar[0]) < 1 || opcode > MAX_OPCODE)
		return ;
	op = g_op_tab[opcode - 1];
//	printf("%s%d\n", op.name, !has_legal_argtypes(ar[1], &op));
	if (op.has_codebyte == 1 && !has_legal_argtypes(ar[1], &op))
		return ;
	if (op.opcode == OP_ST)
		do_st(ar, ps, idx);
	else if (op.opcode == OP_LD)
		do_ld(ar, ps, idx);
}


void		do_st(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
	printf("%D\n%D\n%D\n%D\n%D\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
	if (argtypes[1] == T_REG)
	{
		reg_reg_write(ps, bytes[4], bytes[2]);
	}
	else // already checked for errors, right?
	{
		ind_offset = bigendian_num(bytes + 3, IND_SIZE);
		reg_mem_write(ps, ind_offset, bytes[2], ar);
	}
}

void		do_ld(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
	printf("%0x\n%0x\n%0x\n%0x\n%0x\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
	if (argtypes[0] == T_DIR/* || argtypes[1] == T_IND*/)
	{
		ind_offset = bigendian_num(bytes + 2, DIR_SIZE);
		printf("%lu\n", ind_offset);
		dir_reg_write(ps, bytes[6], ind_offset);
//		printf("%d\n", ps->regs[1]);
	}
	else // already checked for errors, right?
	{
		ind_offset = bigendian_num(bytes + 2, IND_SIZE);
		printf("here %lu\n", ind_offset);
		dir_reg_write(ps, bytes[4], bigendian_num(read_from_arena(ar, ind_offset, REG_SIZE, ps->pc), REG_SIZE));
	}
}

int	main(void)
{
	byte	*mem = calloc(900, 1);
	t_proc	*ps = malloc(sizeof(*ps));

	ps->pc = 0;
	ft_bzero(ps->regs, REG_NUMBER * 8);
//	size_t x = 0xffffffff;
//	memcpy(mem + 1024, &x, 8);
//	memcpy(mem + 1032, &x, 8);
//	ps->regs[2] = 0xAABBCCDD;
//	ps->regs[1] = 0x01;

/*
	mem[0] = 0x03; // OP_ST
	mem[1] = 0x70; // argcodes: 01110000 == T_REG, T_IND
	mem[2] = 0x02; // reg == r2
	mem[3] = 0x00; // ind offset = 0 ...
	mem[4] = 0x0a; // ... + 10
	// so: write the value 0xAABBCCDD at idx offset 10
	// ie, 11 bytes in front of this position
*/
/*
	mem[0] = 0x03; // OP_ST
	mem[1] = 80; // argcodes: 10100000 == T_REG, T_REG
	mem[2] = 0x02; // reg_a == r2
	mem[3] = 0x00; // ind offset = 0 ...
	mem[4] = 0x10; // reg_b == r4
	//writes value of reg2 -> reg4
*/

	mem[0] = 0x02; // OP_ld
	mem[1] = 0x90; // argcodes: 10100000 == T_REG, T_REG
	mem[2] = 255; // %5
	mem[3] = 0; // ind offset = 0 ...
	mem[4] = 0; // ind offset = 0 ...
	mem[5] = 0; // ind offset = 0 ...
	mem[6] = 0x02; // reg_b == r2
	//lds value 0xFF000000 into reg2

/*
	mem[0] = 0x02; // OP_ld
	mem[1] = 0xD0; // argcodes: 10100000 == T_IND, T_REG
	mem[2] = 4; // 4
	mem[3] = 0; // ind offset = 0 ...
	mem[4] = 0x04; // reg_b == r4
	//lds value 5 into reg2
*/
/*
	mem[0] = 0x02; // OP_ST
	mem[1] = 0xD0; // argcodes: 10100000 == T_REG, T_REG
	mem[2] = 0x05; // 5
	mem[3] = 0x00; // ind offset = 0 ...
	mem[4] = 0x02; // reg_b == r2
	//lds value offset 5 into reg2
*/
	puts("BEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, 0, ps);
	puts("AFTER:");
	print_bytes(mem, 20);

	for (int i = 0; i < 16; i++)
		printf("%ld ", ps->regs[i]);
	return (0);
}
