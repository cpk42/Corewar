/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 21:43:47 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 22:07:12 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			do_lfork(t_proc *p)
{
	int			buf;
	int			index;

	vm_read(p->pc, p->pc + 1, &buf, DIR_SIZE);
	index = p->pc + buf;
	add_proc(index, p);
	return (1 + DIR_SIZE);
}

int			do_fork(t_proc *p)
{
	int			buf;
	int			index;

	vm_read(p->pc, p->pc + 1, &buf, DIR_SIZE);
	index = p->pc + (buf % IDX_MOD);
	add_proc(index, p);
	return (1 + DIR_SIZE);
}
