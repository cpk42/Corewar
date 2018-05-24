/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:14:00 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/24 14:40:17 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		read_instr(char *ar, t_proc *ps)
{
	char		opcode;

	if((opcode = ar[0]) < 1 || opcode > MAX_OPCODE)
		return ;
	if (opcode == ST)
	{
		do_st(ps);
	}
	else if (opcode == STI)
	{
		do_sti(ps);
	}
}


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

void	run_tests()
{
	test_st();
	puts("");
	test_sti();
	printf("%d\n", LIVE);
}