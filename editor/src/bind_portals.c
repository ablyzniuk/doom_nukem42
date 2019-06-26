/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_portals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:07:19 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:10 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					intersects(t_edit **edit, t_sect *sect)
{
	t_vertex		*vertex;

	vertex = sect->vertex;
	while (vertex)
	{
		if (check(edit, vertex, sect))
			return (1);
		vertex = vertex->next;
	}
	return (0);
}

void				bind_portals(t_edit **edit, int x, int y)
{
	t_vertex		point;
	t_sect			*sect;

	point.x = x;
	point.y = y;
	if ((*edit)->bind_points[0].x == -1)
		(*edit)->bind_points[0] = point;
	else if ((*edit)->bind_points[1].x == -1)
	{
		(*edit)->bind_points[1] = point;
		sect = (*edit)->sect;
		while (sect)
		{
			if (intersects(edit, sect))
			{
				clear_binder(edit);
				break ;
			}
			sect = sect->next;
		}
		if (!sect)
			clear_binder(edit);
	}
}
