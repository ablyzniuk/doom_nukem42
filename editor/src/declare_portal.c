/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_portal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:08:41 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:20 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					if_close(t_sect *sect, t_vertex *ps, t_vertex *pe)
{
	int				close_at_pos;
	t_vertex		*lst_vertex;
	t_vertex		*vertex;

	close_at_pos = 1;
	lst_vertex = sect->vertex;
	vertex = sect->vertex;
	while (vertex)
	{
		if ((vertex->next == NULL) && ((vertex == ps &&
				lst_vertex == pe) ||
					(vertex == pe &&
						lst_vertex == ps)))
			return (0);
		if ((vertex == ps &&
			vertex->next == pe) ||
				(vertex == pe &&
					vertex->next == ps))
			return (close_at_pos);
		close_at_pos++;
		vertex = vertex->next;
	}
	if (!vertex)
		return (-1);
	return (-1);
}

void				reset_portal_data(t_edit **edit)
{
	(*edit)->portal_in_sect = NULL;
	(*edit)->portal_start = NULL;
	(*edit)->portal_end = NULL;
}

void				to_new_sect(t_edit **edit, t_sect *last_sect, int parent)
{
	t_vertex		*start;
	t_vertex		*end;

	start = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	end = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	start = ft_memcpy(start, (*edit)->portal_start, sizeof(t_vertex));
	end = ft_memcpy(end, (*edit)->portal_end, sizeof(t_vertex));
	last_sect->vertex = start;
	last_sect->vertex->next = end;
	last_sect->vertex->next->next = NULL;
	last_sect->is_child = parent;
}

void				declare_portal(t_edit **edit, int x, int y)
{
	int				index_in_is_portal;
	t_sect			*last_sect;
	t_sect			*sect;

	is_in_radius(edit, (*edit)->zoom, x, y);
	if ((*edit)->portal_in_sect != NULL)
		sect = (*edit)->portal_in_sect;
	if ((*edit)->portal_end != NULL)
	{
		index_in_is_portal = if_close((*edit)->portal_in_sect,
				(*edit)->portal_start, (*edit)->portal_end);
		if (index_in_is_portal != -1)
		{
			last_sect = get_last_sect(edit);
			sect->is_portal[index_in_is_portal] = last_sect->number;
			to_new_sect(edit, last_sect, sect->number);
			(*edit)->sett = vertex;
		}
		reset_portal_data(edit);
	}
}
