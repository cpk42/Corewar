/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/29 10:19:37 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static const char	*token_type_name(g_token_type type) //XXX move to print util
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
		case LABEL_DEFINITION:
			return ("label definition");
		case LABEL_REF_DIRECT:
			return ("label ref direct");
		case LABEL_REF_INDIRECT:
			return ("label ref indirect");
	}
}

void				print_token(t_token *token) //XXX move to print util
{
	printf("%s.%d.%d.",
			token_type_name(token->type),
			token->size,
			token->addr);
	if (HAS_LABEL(token))
		printf("%s\n", token->data.label);
	else
		print_bytes(&(token->data.bytes), token->size);
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
	offset = parent_op_addr - def->addr;
	return (offset);
}

static int			write_one_resolved_token(int fd, t_token *token, t_symtab *symtab, int last_opcode_addr)
{
	int			*bytes_p;

	print_token(token);
	assert(HAS_ADDRESS(token));
	if (IS_UNRESOLVED_LABEL_REF(token))
	{
		//free(token->data);
		token->data.bytes = get_label_offset(token, symtab, last_opcode_addr);
	}
	bytes_p = &(token->data.bytes);
	return (write(fd, bytes_p, token->size));
}

int					write_resolved_tokens(int fd, t_list *token_list, t_symtab *symtab)
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
		maybe_write_err = write_one_resolved_token(fd, token, symtab, last_opcode_addr);
		if (maybe_write_err == -1)
			return (maybe_write_err);
		token_list = token_list->next;
	}
	return (1);
}

int			main(int argc, char **argv)
{

	t_token *token = new_token(OPCODE_TOKEN);
	print_token(token);
	argc = 0;
	argv = 0;
	return (0);
}
