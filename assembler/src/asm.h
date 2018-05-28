/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:24:30 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/28 12:42:47 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "../../corewar/includes/op.h"

# define MAX_OP_LEN		16

/*
**Going to set up a finite state machine struct for each line, unless the
** line is a label.
** NOT SURE IF BUFF SIZE 16 IS CORRECT MAX.
** byte_size is an idea to use for calculating Label offset.
*/

typedef struct			s_fsm
{
	char				buffer[MAX_OP_LEN];
	char				op;
	char				bool_codebyte;
	char				codebyte;
	int					byte_size;
}						t_fsm;

t_fsm					g_fsm;

void					init_fsm();

char					**get_file_array(char *filename);
void					*free_file_array(char **lines);

/*
**IN PROGRESS
** MAKE YOUR CLAIM
** MAX -> fsm_main.c
*/



/*
** Needs to be made
** get_clean_array uses get_file_array. removes all comments and moves leading
**		label into a new inserted line prior to line found. for offset calc.
*/

char					**get_clean_array(char *filename);

/*
**fsm_set_op recieves what SHOULD be a valid op string.
**		sets global g_fsm op
**		sets global g_fsm bool_codebyte
** returns 0 if invalid
*/

int						fsm_set_op(char *op);

/*
**fsm_set_codebyte recieves array of strings that starts at first arg after op.
**ADDITIONALLY, calls fsm_set_arg(..?) to fill global g_fsm buffer for each arg.
**		sets global g_fsm codebyte.
** returns 0 if invalid
*/

int						fsm_set_codebyte(char **parts);

/*
** End of needs
*/


#endif
