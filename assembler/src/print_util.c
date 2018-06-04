/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:15:23 by jgelbard          #+#    #+#             */
/*   Updated: 2018/06/04 14:28:05 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_bytes(void *p, int size)
{
	char	*b;
	int		i;

	b = (char *)p;
	printf("%02X", *b);
	--size;
	++b;
	i = 1;
	while (size > 0)
	{
		if (!(i % 4))
			printf(" ");
		else
			printf(":");
		printf("%02hhX", *b);
		++b;
		--size;
		++i;
	}
	printf("\n");
}

static const char	*token_type_name(g_token_type type)
{
	switch (type)
	{
		case OPCODE_TOKEN:
			return ("opcode");
		case DIRECT_TOKEN:
			return ("direct");
		case INDIRECT_TOKEN:
			return ("indirect");
		case REGISTER_TOKEN:
			return ("register");
		case CODING_BYTE_TOKEN:
			return ("codebyte");
		case LABEL_DEFINITION:
			return ("def");
		case LABEL_REF_DIRECT:
			return ("ref");
		case LABEL_REF_INDIRECT:
			return ("iref");
	}
}

void				print_token(t_token *token)
{
	printf("TOKEN: type '%s', size %d, addr %d, ",
			token_type_name(token->type),
			token->size,
			token->addr);
	if (HAS_LABEL(token))
		printf("label '%s'\n", token->data.label);
	else
	{
		printf("bytes ");
		print_bytes(&(token->data.bytes), token->size);
	}
}

void				print_token_list(t_list *token_list)
{
	t_token		*token;

	while (token_list)
	{
		token = token_list->content;
		print_token(token);
		token_list = token_list->next;
	}
}
