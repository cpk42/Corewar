/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 04:26:24 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/23 22:49:39 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H
# include "corewar.h"

void				initialize_arena(char **p_names);
void				init_error(char *msg);

/*
** Defines and fucntions for reading and writing to/from arena.
*/

# define READ_SIZE 20
/* JOSH */
char		*read_from_arena(char *ar, size_t size, int pc);
char		*lread_from_arena(char *ar, size_t size, int pc);

void		reg_mem_write(char *ar, t_proc *ps, int reg_idx, int dst_idx);
void		lreg_mem_write(char *ar, t_proc *ps, int reg_idx, int dst_idx);
unsigned long	bigendian_num(char *buf, size_t size);
/* ENDJOSH */

char				*vm_rawread(int pc, int index, size_t size);
char				*vm_lrawread(int index, size_t size);
void				vm_write(int pc, int index, void *src, size_t size);
void				vm_lwrite(int index, void *src, size_t size);
void				vm_read(int pc, int index, void *dst, size_t size);
void				vm_lread(int index, void *dst, size_t size);

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
