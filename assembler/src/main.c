/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:46:46 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/29 13:14:56 by jgelbard         ###   ########.fr       */
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

void				print_token(t_token *token) //XXX move to print util
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
		//puts("a");
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

t_token *make_fake_def(char *label, int addr)
{
	t_token *fake = new_token(LABEL_DEFINITION);
	fake->addr = addr;
	fake->data.label = label;
	return (fake);
}

t_symtab	*fake_symtab(void)
{
	t_symtab *symtab = ft_lstnew(make_fake_def("loop", 0), sizeof(t_token));
	ft_lstadd(&symtab, ft_lstnew(make_fake_def("somelabel", 9), sizeof(t_token)));
	return (symtab);
}

t_token *quick_token(g_token_type type, int size, int addr, char *label, int bytes)
{
	t_token *t = new_token(type);
	t->size = size;
	t->addr = addr;
	if (label)
		t->data.label = label;
	else
		t->data.bytes = bytes;
	return (t);
}

t_list		*resoluble_tokens(void)
{
	t_token *live = quick_token(OPCODE_TOKEN, 1, 0, NULL, 1);
	t_token *d39 = quick_token(DIRECT_TOKEN, 4, 1, NULL, 0x27);
	t_token *sti = quick_token(OPCODE_TOKEN, 1, 5, NULL, 0x0b);
	t_token *codebyte = quick_token(CODING_BYTE_TOKEN, 1, 6, NULL, 0x78);
	t_token *r2 = quick_token(REGISTER_TOKEN, 1, 7, NULL, 0x02);
	t_token *i10 = quick_token(INDIRECT_TOKEN, 2, 8, NULL, 0x0a);
	t_token *d2 = quick_token(DIRECT_TOKEN, 2, 10, NULL, 0x02);
	t_token *zjmp = quick_token(OPCODE_TOKEN, 1, 12, NULL, 0x09);
	t_token *ref = quick_token(LABEL_REF_DIRECT, 2, 13, "loop", 0);
	t_list *list = ft_lstnew(ref, sizeof(t_token));
	ft_lstadd(&list, ft_lstnew(zjmp, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(d2, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(i10, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(r2, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(codebyte, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(sti, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(d39, sizeof(t_token)));
	ft_lstadd(&list, ft_lstnew(live, sizeof(*live)));
	return (list);
}

int			main(int argc, char **argv)
{
	t_list *token_list = resoluble_tokens();
	t_symtab *symtab = fake_symtab();
	char *scrap = "player.cor";
	int fd = open(scrap, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0777);
	write_resoluble_tokens(fd, token_list, symtab);
	argc = 0;
	argv = 0;
	return (0);
}
