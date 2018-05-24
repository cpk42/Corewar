/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 22:38:07 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		read_instr(byte *ar, t_proc *ps)
{
	byte		opcode;

	if((opcode = ar[0]) < 1 || opcode > MAX_OPCODE)
		return ;
	if (opcode == OP_ST)
		do_st(ar, ps);
	else if (opcode == OP_STI)
	{
		do_sti(ar, ps);
	}
}

void	test_st(void)
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
	puts("test_st\nBEFORE:");
	print_bytes(mem, 20);
	read_instr(mem, ps);
	puts("AFTER:");
	print_bytes(mem, 20);
}

void	test_sti(void)
{
	byte	*mem = calloc(900, 1);
	t_proc	*ps = malloc(sizeof(*ps));

	ps->pc = 0;
	ft_bzero(ps->regs, sizeof(ps->regs));
	ps->regs[2] = 0xAABBCCDD;

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
}

static void			usage(void)
{
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
	}
	else
		usage();
	test_st();
	puts("");
	test_sti();
	return (0);
}
