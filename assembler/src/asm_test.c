/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:14:05 by jgelbard          #+#    #+#             */
/*   Updated: 2018/06/04 14:03:51 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token *quick_token(g_token_type type, int size, int addr, char *label, int bytes)
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

static t_list		*resoluble_tokens(void)
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

static t_token *make_fake_def(char *label, int addr)
{
	t_token *fake = new_token(LABEL_DEFINITION);
	fake->addr = addr;
	fake->data.label = label;
	return (fake);
}

static t_symtab		*fake_symtab(void)
{
	t_symtab *symtab = ft_lstnew(make_fake_def("loop", 0), sizeof(t_token));
	ft_lstadd(&symtab, ft_lstnew(make_fake_def("somelabel", 9), sizeof(t_token)));
	return (symtab);
}

void test_asm(void)
{
	t_list *token_list = resoluble_tokens();
	t_symtab *symtab = fake_symtab();
	char *scrap = "player.cor";
	int fd = open(scrap, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0777);
	write_resoluble_tokens(fd, token_list, symtab);
}
