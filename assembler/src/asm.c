/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/04 14:28:58 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

t_token				*new_token(g_token_type type)
{
	t_token			*token;

	token = malloc(sizeof(*token));
	token->type = type;
	token->size = -1;
	token->addr = -1;
	token->data.bytes = 0xFFFFFFFF;
	token->data.label = NULL;
	return (token);
}

t_token				*get_defined_label(char *label, t_symtab *symtab)
{
	t_token		*try_match;
	t_token		*match;

	match = NULL;
	while (symtab)
	{
		try_match = symtab->content;
		assert(try_match->type == LABEL_DEFINITION && HAS_ADDRESS(try_match));
		if (!ft_strcmp(label, try_match->data.label))
		{
			match = try_match;
			break;
		}
		symtab = symtab->next;
	}
	return (match);
}

int					get_label_offset(t_token *token, t_symtab *symtab, int parent_op_addr)
{
	t_token		*def;
	int			offset;

	assert(IS_UNRESOLVED_LABEL_REF(token));
	def = get_defined_label(token->data.label, symtab);
	assert(def != NULL && HAS_ADDRESS(def));
	offset = def->addr - parent_op_addr;
	return (offset);
}

static int			write_one_resoluble_token(int fd, t_token *token, t_symtab *symtab, int last_opcode_addr)
{
	int			bytes;

	assert(HAS_ADDRESS(token));
	if (IS_UNRESOLVED_LABEL_REF(token))
		bytes = get_label_offset(token, symtab, last_opcode_addr);
	else
		bytes = token->data.bytes;
	reverse_bytes(&bytes, token->size);
	return (write(fd, &bytes, token->size));
}

int					write_resoluble_tokens(int fd, t_list *token_list, t_symtab *symtab)
{
	t_token		*token;
	int			last_opcode_addr;
	int			maybe_write_err;

	token = NULL;
	while (token_list)
	{
		token = token_list->content;
		assert(token != NULL && HAS_ADDRESS(token));
		if (token->type == OPCODE_TOKEN)
			last_opcode_addr = token->addr;
		maybe_write_err = write_one_resoluble_token(fd, token, symtab, last_opcode_addr);
		if (maybe_write_err == -1)
		{
			perror(NULL);
			return (maybe_write_err);
		}
		token_list = token_list->next;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	test_asm();
	argc = 0;
	argv = 0;
	return (0);
}
