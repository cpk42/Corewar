/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:01:40 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/28 14:07:10 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			del_player(t_player **p)
{
	free(*p);
	*p = 0;
}

static void		st_get_str(int fd, char *tmp, int len)
{
	char		buf[MEM_SIZE];
	int			read_num;

	if ((read_num = read(fd, buf, len)) != len)
		init_error("Invalid champion file.");
	ft_memcpy(tmp, buf, len);
}

static void		st_get_int(int fd, unsigned int *tmp)
{
	char		buf[4];
	int			read_num;

	if ((read_num = read(fd, buf, 4)) != 4)
		init_error("Invalid champion file. int");
	endian_swap(buf, 4);
	*tmp = *(unsigned int *)buf;
}

void			new_player(char *file_name, t_player *tmp)
{
	int			fd;
	static int	id = 0;

	if((fd = open(file_name, O_RDONLY)) < 0)
		return ;
	st_get_int(fd, &tmp->h.magic);
	st_get_str(fd, (char *)tmp->h.prog_name, PROG_NAME_LENGTH + 4);
	st_get_int(fd, &tmp->h.prog_size);
	st_get_str(fd, (char *)tmp->h.comment, COMMENT_LENGTH + 4);
	ft_bzero((void *)tmp->code, CHAMP_MAX_SIZE);
	st_get_str(fd, (char *)tmp->code, tmp->h.prog_size);
	tmp->id = id++;
	tmp->start_idx = 0;
}
