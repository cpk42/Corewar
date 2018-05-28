/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <mmoros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:06:29 by mmoros            #+#    #+#             */
/*   Updated: 2018/05/28 12:40:15 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_fsm(void)
{
	ft_bzero(g_fsm.buffer, MAX_OP_LEN);
	g_fsm.op = 0;
	g_fsm.bool_codebyte = 0;
	g_fsm.codebyte = 0;
	g_fsm.byte_size = 0;
}
