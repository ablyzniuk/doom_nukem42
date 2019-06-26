/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_sect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:11 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:35 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					orientation(t_vertex p1, t_vertex p2, t_vertex p3)
{
	int				value;
	int				ret;

	value = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
	if (value == 0)
		return (0);
	ret = value > 0 ? 1 : 2;
	return (ret);
}

int					inter(t_vertex v1, t_vertex v2, t_vertex p1, t_vertex p2)
{
	t_intersect		var;

	var.o1 = orientation(v1, v2, p1);
	var.o2 = orientation(v1, v2, p2);
	var.o3 = orientation(p1, p2, v1);
	var.o4 = orientation(p1, p2, v2);
	if (var.o1 != var.o2 && var.o3 != var.o4)
		return (1);
	return (0);
}

int					inters(t_vertex *pvertex, t_vertex point, t_vertex extreme)
{
	int				num_of_intersects;
	t_vertex		*vertex;

	num_of_intersects = 0;
	vertex = pvertex;
	while (vertex)
	{
		if (vertex->next == NULL)
		{
			if (inter(*vertex, *(pvertex), point, extreme))
				num_of_intersects++;
		}
		else if (inter(*vertex, *(vertex->next), point, extreme))
			num_of_intersects++;
		vertex = vertex->next;
	}
	return (num_of_intersects);
}

int					is_inside_sect(t_edit *edit, t_vertex point)
{
	int				num_of_intersects;
	t_sect			*sect;
	t_vertex		*vertex;
	t_vertex		extreme;

	sect = edit->sect;
	while (sect)
	{
		extreme.x = WIN_W;
		extreme.y = point.y;
		vertex = sect->vertex;
		num_of_intersects = inters(vertex, point, extreme);
		if (num_of_intersects % 2 == 1)
			return (sect->number);
		sect = sect->next;
	}
	return (-1);
}
