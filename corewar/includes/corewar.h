/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/17 05:29:29 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include "arena.h"

/*
** Global declaration of arena & associated (void *).
** Do not reference g_ARENA_MEMORY[]. This is just the declaration.
** Make copies of the pointer to access the memory.
*/

char				g_ARENA_MEMORY[MEM_SIZE];
void				*g_arena;

/*
** WIP struct for proccesses.
*/

typedef struct		s_proc
{
	char		*name;
	char		*comment;
	int			proc_id;
	void		*pc;
	t_proc		*next;
//	t_proc		*prev;
}					t_proc;

/*
** Function declarations.
** t_proc functions:
*/

t_proc				*new_proc(char *name, char *comment, int mem_idx);

#endif
