/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_portals_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:30:10 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:13 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					compare_coords(t_vertex *p1, t_vertex *a, t_vertex *b)
{
	if (p1->x == a->x && p1->y == a->y)
		return (1);
	if (p1->x == b->x && p1->y == b->y)
		return (1);
	return (0);
}

void				save(t_edit **edit, t_sect *s, t_vertex *p1, t_vertex *p2)
{
	int				at;
	int				wc;

	if ((*edit)->in_which == NULL)
	{
		(*edit)->in_which = s;
		(*edit)->ab = p1;
		(*edit)->cd = p2;
	}
	else if ((*edit)->in_which != NULL)
	{
		if (compare_coords(p1, (*edit)->ab, (*edit)->cd) == 0 ||
			compare_coords(p2, (*edit)->ab, (*edit)->cd) == 0)
			clear_binder(edit);
		else
		{
			at = if_close(s, p1, p2);
			s->is_portal[at] = (*edit)->in_which->number;
			wc = if_close((*edit)->in_which, (*edit)->ab, (*edit)->cd);
			(*edit)->in_which->is_portal[wc] = s->number;
		}
	}
}

int					check(t_edit **edit, t_vertex *vertex, t_sect *sect)
{
	static int		n = 0;

	if (vertex->next == NULL)
	{
		if (inter(*vertex, *(sect->vertex),
				(*edit)->bind_points[0], (*edit)->bind_points[1]))
		{
			save(edit, sect, vertex, sect->vertex);
			n++;
		}
	}
	else if (inter(*vertex, *(vertex->next),
			(*edit)->bind_points[0], (*edit)->bind_points[1]))
	{
		save(edit, sect, vertex, vertex->next);
		n++;
	}
	if (n == 2)
	{
		n = 0;
		return (1);
	}
	return (0);
}

void				clear_binder(t_edit **edit)
{
	(*edit)->bind_points[0].x = -1;
	(*edit)->bind_points[0].y = -1;
	(*edit)->bind_points[1].x = -1;
	(*edit)->bind_points[1].y = -1;
	(*edit)->in_which = NULL;
	(*edit)->ab = NULL;
	(*edit)->cd = NULL;
}
