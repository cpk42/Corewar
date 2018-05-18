/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:48:14 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/18 08:31:17 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include "arena.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> //printf

/*
** WIP struct for players.
*/

typedef struct		s_player
{
	header_t			h;
	char				id;
	int					start_idx;
	char				code[CHAMP_MAX_SIZE];
}					t_player;

/*
** Player functions.
*/

t_player			*new_player(char *file_name);

/*
** WIP struct for proccesses.
*/

typedef struct		s_proc
{
	int					proc_id;
	int					pc;
	struct s_proc		*next;
//	t_proc		*prev;
}					t_proc;

/*
** t_proc functions:
*/

t_proc				*new_proc(int mem_idx);

#endif
