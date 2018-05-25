/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 04:26:24 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/24 14:42:32 by jgelbard         ###   ########.fr       */
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

/* JOSH */
/* 'public api' */
void			store_register_contents(t_proc *ps, int reg_num, int req_idx);
unsigned long	bigendian_num(char *buf, size_t size);
int				get_int(t_proc *ps, int req_idx);
int				get_short(t_proc *ps, int req_idx);
int				get_byte(t_proc *ps, int req_idx);
int				follow_indirect_reference(t_proc *ps, int index_of_indirect);
/* internals */
void		_store_register_contents(t_proc *ps, int reg_idx, int req_idx);
void		_lstore_register_contents(t_proc *ps, int reg_idx, int req_idx);
char		*_process_read(t_proc *ps, int req_idx, size_t size);
char		*_process_lread(t_proc *ps, int req_idx, size_t size);
/* ENDJOSH */

#endif
