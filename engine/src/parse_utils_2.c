/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:27 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:18:30 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_list			*find_elem(t_list *list, char *elem)
{
	while (!ft_strstr((char *)list->content, elem))
		list = list->next;
	return (list);
}

t_sector		*allocate_sector(size_t size)
{
	t_sector	*sector;

	if (!(sector = (t_sector *)ft_memalloc(sizeof(t_sector) * size)))
		print_error(BAD_ALLOC);
	return (sector);
}

t_decor			*allocate_decor(size_t size)
{
	t_decor		*decor;

	if (!(decor = (t_decor *)ft_memalloc(sizeof(t_decor) * size)))
		print_error(BAD_ALLOC);
	return (decor);
}

t_enemy			*allocate_enemy(size_t size)
{
	t_enemy		*enemy;

	if (!(enemy = (t_enemy *)ft_memalloc(sizeof(t_enemy) * size)))
		print_error(BAD_ALLOC);
	return (enemy);
}

double			**allocate_vertex_array(size_t size)
{
	double		**array;

	if (!(array = (double **)ft_memalloc(sizeof(double *) * size + 1)))
		print_error(BAD_ALLOC);
	return (array);
}
