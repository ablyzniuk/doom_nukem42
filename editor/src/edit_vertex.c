/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:08 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:30 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				redefine_position(t_edit **edit, int x, int y)
{
	t_sect			*sect;
	t_vertex		*it;

	sect = (*edit)->sect;
	while (sect)
	{
		it = sect->vertex;
		while (it)
		{
			if (it->x == (*edit)->to_edit->x && it->y == (*edit)->to_edit->y)
			{
				it->x = x;
				it->y = y;
			}
			it = it->next;
		}
		sect = sect->next;
	}
	(*edit)->to_edit->x = x;
	(*edit)->to_edit->y = y;
	(*edit)->to_edit = NULL;
}

void				edit_vertex(t_edit **edit, int x, int y)
{
	t_vertex		*vertex;

	x = (x / (*edit)->zoom) * (*edit)->zoom;
	y = (y / (*edit)->zoom) * (*edit)->zoom;
	if ((*edit)->to_edit == NULL)
	{
		if ((vertex = is_present((*edit)->vertex, x, y)) != NULL)
			(*edit)->to_edit = vertex;
	}
	else
		redefine_position(edit, x, y);
}
