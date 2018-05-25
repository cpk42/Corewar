/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/23 22:26:47 by ckrommen         ###   ########.fr       */
=======
/*   Updated: 2018/05/24 14:17:49 by jgelbard         ###   ########.fr       */
>>>>>>> 50587556e69e31d5b2865c57cdc35477cbb041e1
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
void		do_st(byte *ar, t_proc *ps, int idx);
void		do_ld(byte *ar, t_proc *ps, int idx);
void		do_add(byte *ar, t_proc *ps, int idx);
void		do_sub(byte *ar, t_proc *ps, int idx);
void		do_and(byte *ar, t_proc *ps, int idx);
void		do_or(byte *ar, t_proc *ps, int idx);
void		do_xor(byte *ar, t_proc *ps, int idx);
=======
void run_tests(void);
>>>>>>> 50587556e69e31d5b2865c57cdc35477cbb041e1

static void			usage(void)
{
<<<<<<< HEAD
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
	else if (op.opcode == OP_ADD)
		do_add(ar, ps, idx);
	else if (op.opcode == OP_SUB)
		do_sub(ar, ps, idx);
	else if (op.opcode == OP_AND)
		do_and(ar, ps, idx);
//	else if (op.opcode == OP_OR)
//		do_or(ar, ps, idx);
//	else if (op.opcode == OP_XOR)
//		do_xor(ar, ps, idx);
}


void		do_st(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
//	printf("%D\n%D\n%D\n%D\n%D\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
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
//	printf("%0x\n%0x\n%0x\n%0x\n%d\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
	if (argtypes[0] == T_DIR)
	{
		ind_offset = bigendian_num(bytes + 2, DIR_SIZE);
		dir_reg_write(ps, bytes[6], ind_offset);
	}
	else // already checked for errors, right?
	{
		ind_offset = bigendian_num(bytes + 2, IND_SIZE);
		dir_reg_write(ps, bytes[4], bigendian_num(read_from_arena(ar, ind_offset, REG_SIZE, ps->pc), REG_SIZE));
	}
}

void		do_add(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
//	printf("%0x\n%0x\n%0x\n%0x\n%d\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
	ps->regs[bytes[4] - 1] = ps->regs[bytes[2] - 1] + ps->regs[bytes[3] - 1];
	if (!ps->regs[bytes[4] - 1])
		ps->carry = 1;
	else
		ps->carry = 0;
}

void		do_sub(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
//	printf("%0x\n%0x\n%0x\n%0x\n%d\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
	ps->regs[bytes[4] - 1] = ps->regs[bytes[2] - 1] - ps->regs[bytes[3] - 1];
	if (!ps->regs[bytes[4] - 1])
		ps->carry = 1;
	else
		ps->carry = 0;
}

void		do_and(byte *ar, t_proc *ps, int idx)
{
	byte			*bytes;
	t_arg_type		*argtypes;
	unsigned long	ind_offset;

	bytes = read_from_arena(ar, idx, 16, ps->pc);
	argtypes = extract_argtypes(bytes[1]);
	printf("%0x\n%0x\n%0x\n%0x\n%d\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
	printf("args= %d %d %d \n", argtypes[0], argtypes[1], argtypes[2]);
	if (argtypes[0] && argtypes[1])
		ps->regs[bytes[4] - 1] = ps->regs[bytes[2] - 1] & ps->regs[bytes[3] - 1];
	else if (argtypes[0] == 2 && argtypes[1] == 2)
		ps->regs[bigendian_num(bytes[4] - 1, T_REG)] = bigendian_num(bytes[2], T_DIR) & bytes[3];
	else if (argtypes[0] == 3 && argtypes[1] == 2)
	{
		ind_offset = bigendian_num(bytes + 2, IND_SIZE);
		dir_reg_write(ps, bytes[4], bigendian_num(read_from_arena(ar, ind_offset, REG_SIZE, ps->pc), REG_SIZE));
	}
	if (!ps->regs[bytes[4] - 1])
		ps->carry = 1;
	else
		ps->carry = 0;
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
/*
	mem[0] = 0x02; // OP_ld
	mem[1] = 0x90; // argcodes: 10100000 == T_DIR, T_REG
	mem[2] = 0; // %255
	mem[3] = 0; // ind offset = 0 ...
	mem[4] = 0; // ind offset = 0 ...
	mem[5] = 5; // ind offset = 0 ...
	mem[6] = 0x02; // reg_b == r2
	//lds value 0xFF000000 into reg2
*/
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
/*
	ps->regs[0] = 1;
	ps->regs[1] = 1;
	mem[0] = 0x04; // OP_ADD
	mem[1] = 0x54; // 01010100 t_reg t_reg t_reg
	mem[2] = 0x01; // reg1
	mem[3] = 0x02; // reg2
	mem[4] = 0x03; // reg3
	//add r1 + r2 -> r3
*/
/*
	ps->regs[0] = 2;
	ps->regs[1] = 1;
	mem[0] = 0x05; // OP_SUB
	mem[1] = 0x54; // 01010100 t_reg t_reg t_reg
	mem[2] = 0x01; // reg1
	mem[3] = 0x02; // reg2
	mem[4] = 0x03; // reg3
	//sub r1 - r2 -> r3
*/
	ps->regs[0] = 1;
	ps->regs[1] = 1;
	mem[0] = 0x06; // OP_SUB
	mem[1] = 0x54; // 01010100 t_reg t_reg t_reg
	mem[2] = 0x01; // reg1
	mem[3] = 0x02; // reg2
	mem[4] = 0x03; // reg3
	//and r1 - r2 -> r3

	puts("BEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, 0, ps);
	puts("AFTER:");
	print_bytes(mem, 20);

	for (int i = 0; i < 16; i++)
		printf("%ld ", ps->regs[i]);
=======
	ft_putendl("Ya dun goofed.");
}

int			main(int argc, char **argv)
{
	ft_putendl("Hello Corewar!");
	if (argc - 1 >= 1 && argc - 1 <= MAX_PLAYERS)
	{
		initialize_vm(argc - 1);
		initialize_arena(argv + 1);
		ft_putendl("\n");
		run_tests();
	}
	else
		usage();
>>>>>>> 50587556e69e31d5b2865c57cdc35477cbb041e1
	return (0);
}
