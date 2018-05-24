/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 04:16:44 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/24 12:51:55 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** This file contains utility functions for t_proc's.
*/

/*
** Adds a t_proc to the head of the list pointed to by g_vm.proc_head.
** Meant for use by fork / lfork.
*/

void			add_proc(int mem_idx, t_proc *parent)
{
	t_proc		*new;

	new = new_proc(mem_idx, parent);
	new->next = g_vm.proc_head->next;
	g_vm.proc_head = new;
}

/*
** Delinks and deletes a t_proc. Free()'s memory as neccessary,
** and sets the passed t_proc pointer to null.
*/

void			del_proc(t_proc **p)
{
	g_vm.proc_num--;
	if ((*p)->next)
		(*p)->next->prev = (*p)->prev;
	if ((*p)->prev)
		(*p)->prev->next = (*p)->next;
	free(*p);
	*p = 0;
}

/*
** Copies registers if parent != NULL.
*/

static void		st_cpyregs(t_proc *p, t_proc *c)
{
	int				i;

	i = 0;
	while (++i < REG_NUMBER)
	{
		if (!p)
			c->regs[i] = 0;
		else
			c->regs[i] = p->regs[i];
	}
}

/*
** Creates a new t_proc.
** Uses a static int to keep track of how many t_proc's
** have already been made.
**
** Returns a pointer to the fresh t_proc with accurate proc_id.
*/

t_proc			*new_proc(int mem_idx, t_proc *parent)
{
	static int		proc_id = 0;
	t_proc			*tmp;

	g_vm.proc_num++;
	if (!(tmp = (t_proc *)ft_memalloc(sizeof(t_proc))))
		return (0);
	tmp->proc_id = proc_id++;
	tmp->pc = mem_idx;
	tmp->next = 0;
	tmp->prev = 0;
	tmp->lcount = 0;
	tmp->tminus = 0;
	tmp->carry = 0;
	st_cpyregs(parent, tmp);
	return (tmp);
}
