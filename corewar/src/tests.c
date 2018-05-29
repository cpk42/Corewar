/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:14:00 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/28 21:32:40 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		read_instr(char *ar, t_proc *ps)
{
	char		opcode;

	if((opcode = ar[0]) < 1 || opcode > MAX_OPCODE)
		return ;
	if (opcode == ST)
		do_st(ps);
	else if (opcode == STI)
		do_sti(ps);
	else if (opcode == LD)
		do_ld(ps);
	else if (opcode == ADD)
		do_add(ps);
	else if (opcode == SUB)
		do_sub(ps);
	else if (opcode == AND)
		do_and(ps);
	else if (opcode == OR)
		do_or(ps);
	else if (opcode == XOR)
		do_xor(ps);
	else if (opcode == LDI)
		do_ldi(ps);
}
/*
static void		test_st(void)
{
	char	*og_arena = g_arena;
	char	*mem = calloc(900, 1);
	g_arena = mem;
	t_proc	*ps = calloc(sizeof(*ps), 1);

	ps->pc = 0;
	ft_bzero(ps->regs, sizeof(ps->regs));
	ps->regs[1] = 0x66666666;

	mem[0] = 0x03; // OP_ST
	mem[1] = 0x70; // argcodes: 10110000 == T_REG, T_IND
	mem[2] = 0x02; // reg == r2
	mem[3] = 0x00; // ind offset = 0 ...
	mem[4] = 0x0a; // ... + 10
	mem[11] = 0x00; // the ind offset takes us here...
	mem[13] = 0x0A; // and we read a 10
	// so: write the value 0x66666666 at idx offset 10
	// ie, 11 bytes in front of this position
	puts("test_st\nBEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, ps);
	puts("AFTER:");
	print_bytes(mem, 20);
	g_arena = og_arena;
}

static void		test_sti(void)
{
	char	*og_arena = g_arena;
	char	*mem = calloc(900, 1);
	g_arena = mem;
	t_proc	*ps = calloc(sizeof(*ps), 1);

	ps->pc = 0;
	ft_bzero(ps->regs, sizeof(ps->regs));
	ps->regs[1] = 0xAABBCCDD;

	mem[0] = 0x0B; // OP_STI
	mem[1] = 0x68; // argcodes: 10010100 == T_REG, T_DIR, T_DIR -- DIRS are truncated, though
	mem[2] = 0x02; // reg == r2
	mem[3] = 0x00; // first dir value == ...
	mem[4] = 0x05; // ... 5
	mem[5] = 0x00; // second dir value
	mem[6] = 0x05; // ... 5
	// so: write the value 0xAABBCCDD at idx offset 10
	// ie, 11 bytes in front of this position
	puts("test_sti\nBEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, ps);
	puts("AFTER:");
	print_bytes(mem, 20);
	g_arena = og_arena;
}
*/
/*
static void		test_ld(void)
{
	char	*og_arena = g_arena;
	char	*mem = calloc(900, 1);
	g_arena = mem;
	t_proc	*ps = calloc(sizeof(*ps), 1);

	ps->pc = 0;
	ft_bzero(ps->regs, sizeof(ps->regs));
//	ps->regs[1] = 0x66666666;
	mem[0] = 0x02; // OP_ld
	mem[1] = 0x90; // argcodes: 10100000 == T_DIR, T_REG
	mem[2] = 0; // %255
	mem[3] = 0; // ind offset = 0 ...
	mem[4] = 0; // ind offset = 0 ...
	mem[5] = 5; // ind offset = 0 ...
	mem[6] = 0x02; // reg_b == r2
	//lds value 0xFF000000 into reg2

	puts("test_st\nBEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, ps);
	puts("AFTER:");
	print_bytes(mem, 20);
	print_registers(ps);
	g_arena = og_arena;
}
*/

static void		test_ld(void)
{
	char	*og_arena = g_arena;
	char	*mem = calloc(900, 1);
	g_arena = mem;
	t_proc	*ps = calloc(sizeof(*ps), 1);

	ps->pc = 0;
	ft_bzero(ps->regs, sizeof(ps->regs));
//	ps->regs[0] = 0;
//	ps->regs[1] = 0;
//	ps->regs[2] = 0;
	mem[0] = 0x09; // OP_and
	mem[1] = 0x80; // argcodes: 11100100 == ind, dir, reg
	mem[2] = 0; // 1
	mem[3] = 8; // 1
	puts("test_st\nBEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, ps);
	puts("AFTER:");
	print_bytes(mem, 20);
	print_registers(ps);
	g_arena = og_arena;
}

void	run_tests()
{
//	test_st();
//	puts("");
//	test_sti();
//	printf("%d\n", LIVE);
	test_ld();
}
