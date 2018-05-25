/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:36:16 by ckrommen          #+#    #+#             */
/*   Updated: 2018/05/21 13:21:13 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct OBJECT_t
{
	uint8_t type;

	union {
		uint8_t		u8;
		int8_t		i8;
		uint32_t	u32;
		int32_t		i32;
		void		*ptr;
	};
}				OBJECT;

typedef struct	STACK_t
{
	int top;
	int size;
	OBJECT *stack;
}				STACK;

STACK stack_new(int size)
{
	STACK s;
	s.top = 0;
	s.size = size;
	s.stack = (OBJECT *)malloc(sizeof(OBJECT) * size);
	return (s);
}

STACK stack_push(STACK *s, OBJECT o)
{
	s->stack[s->top++] = o;
	return (s->top);
}

STACK stack_pop(STACK *s)
{
	return (s->stack[--(s->top)]);
}

STACK stack_peek(STACK *s)
{
	return (s->stack[s->top - 1]);
}
uint8_t	*load_file(char *filename)
{
	FILE *f;
	int size;

	
}
int main(int argc, char **argv)
{
	uint8_t *code;

	
	return (0);
}
