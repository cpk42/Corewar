/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 04:26:24 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/18 10:32:45 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

void				initialize_arena(int ac, char **av);
void				init_error(char *msg);

/*
** Union to allow easy passing of memory location values.
** 
** Usage: 	t_val		temp;
** 			t_val		*ptr;
**
** 			temp.i = (int);
** 			ptr->i = (int);
*/

typedef union			u_val
{
	int			i;
	short		s;
	char		c;
}						t_val;

/*
** Defines and fucntions for reading and writing to/from arena.
*/

# define PLAYER1 1
# define PLAYER2 2
# define PLAYER3 4
# define PLAYER4 8

# define CHAR_TYPE 1
# define SHORT_TYPE 2
# define INT_TYPE 4

int					write_to_arena(int index, char TYPE, t_val val);
t_val				read_from_arena(int index, char TYPE);
char				get_memory_owner(int index);

/*
** Internal utility functions.
*/

void				endian_swap(char *mem, int size);

/*
** Global declaration of arena & associated (char *).
** Do not reference g_ARENA_MEMORY[].
** This is just the declaration.
** Make a copy of the pointer for direct access.
*/

char				g_ARENA_MEMORY[MEM_SIZE];
char				*g_arena;

#endif
