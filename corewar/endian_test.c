/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 05:50:59 by ltanenba          #+#    #+#             */
/*   Updated: 2018/05/17 05:52:59 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		main(void) 
{
	unsigned int 	i = 1;
	char			*c = (char*)&i;

	if (*c)    
		printf("Little endian");
	else
		printf("Big endian");
	getchar();
	return 0;
}
