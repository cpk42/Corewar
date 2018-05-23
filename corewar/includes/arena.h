/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 04:26:24 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/19 06:40:43 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

void				initialize_arena(int ac, char **av);
void				init_error(char *msg);

/*
** Defines and fucntions for reading and writing to/from arena.
*/

void				write_to_arena(int index, void *src, unsigned int size);
void				read_from_arena(int index, void *dst, unsigned int size);

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
