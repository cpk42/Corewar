/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:24:30 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/29 12:10:30 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "corewar.h"

typedef enum		e_token_type
{
	OPCODE_TOKEN,
	DIRECT_TOKEN,
	INDIRECT_TOKEN,
	REGISTER_TOKEN,
	CODING_BYTE_TOKEN,
	LABEL_DEFINITION,
	LABEL_REF_DIRECT,
	LABEL_REF_INDIRECT
}					g_token_type;

# define IS_UNRESOLVED_LABEL_REF(token) (token->type == LABEL_REF_DIRECT || token->type == LABEL_REF_INDIRECT)
# define HAS_LABEL(token) (token->type == LABEL_DEFINITION || token->type == LABEL_REF_DIRECT || token->type == LABEL_REF_INDIRECT)
# define HAS_ADDRESS(token) (token->addr >= 0)

typedef struct		s_token
{
	g_token_type	type;
	int				size;
	int				addr;
	union
	{
		int			bytes;
		char		*label;
	}				data;
}					t_token;

typedef struct		s_writer
{
	t_list			*token_stream;
	int				fd;
	int				pc;
}					t_writer;

typedef t_list		t_symtab;

/* debug */

void				reverse_bytes(void *_bytes, size_t size);

t_token				*new_token(g_token_type type);
int					write_resoluble_tokens(int fd, t_list *token_list, t_symtab *symtab);

/* debug */

void				test_asm();
void				print_token_list(t_list *token_list);
void				print_token(t_token *token);
#endif
