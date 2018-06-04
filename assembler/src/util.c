/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:19:35 by jgelbard          #+#    #+#             */
/*   Updated: 2018/05/29 17:20:10 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		reverse_bytes(void *_bytes, size_t size)
{
	char *bytes = (char *)_bytes;
	char tmp;
	size_t i = 0;
	while (i < size / 2)
	{
		tmp = bytes[size - i - 1];
		bytes[size - i - 1] = bytes[i];
		bytes[i] = tmp;
		++i;
	}
}
