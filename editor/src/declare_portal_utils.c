/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_portal_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:08:46 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:22 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				assign_portal(t_edit **edit, t_sect *sect, t_vertex *vertex)
{
	if ((*edit)->portal_in_sect == NULL && (*edit)->portal_start == NULL)
	{
		(*edit)->portal_in_sect = sect;
		(*edit)->portal_start = vertex;
	}
	else if ((*edit)->portal_end == NULL && (*edit)->portal_in_sect == sect)
		(*edit)->portal_end = vertex;
}

void				is_in_radius(t_edit **edit, int radius, int x, int y)
{
	t_sect			*sect;
	t_vertex		*vertex;
	int				dx;
	int				dy;

	sect = (*edit)->sect;
	while (sect)
	{
		vertex = sect->vertex;
		while (vertex)
		{
			dx = abs(x - vertex->x);
			dy = abs(y - vertex->y);
			if (dx + dy <= radius || (dx * dx) + (dy * dy) <= radius)
				assign_portal(edit, sect, vertex);
			vertex = vertex->next;
		}
		sect = sect->next;
	}
}
