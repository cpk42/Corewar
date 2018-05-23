/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 04:16:44 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 14:54:02 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** This file contains utility functions for t_proc's.
*/

/*
** Adds a t_proc to the head of the list pointed to by **head.
*/

void			add_proc(t_proc **head, t_proc *new)
{
	new->next = *head;
	*head = new;
}

/*
** Deletes a t_proc. Free()'s memory as neccessary,
** and sets the passed t_proc pointer to null.
*/

void			del_proc(t_proc **p)
{
	free(*p);
	*p = 0;
}

/*
** Creates a new t_proc.
** Uses a static int to keep track of how many t_proc's 
** have already been made.
**
** Returns a pointer to the fresh t_proc with accurate proc_id.
*/

t_proc			*new_proc(int mem_idx)
{
	static int		proc_id = 0;
	t_proc			*tmp;

	if (!(tmp = (t_proc *)ft_memalloc(sizeof(t_proc))))
		return (0);
	tmp->proc_id = proc_id++;
	tmp->pc = mem_idx;
	tmp->next = 0;
	tmp->prev = 0;
	return (tmp);
}
