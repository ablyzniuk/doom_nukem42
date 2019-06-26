/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:08:57 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:26 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					get_color(t_sect *sect, int *i)
{
	int				color;

	if (sect->is_portal != NULL && *i >= sect->vertex_count)
		*i = 0;
	if (sect->is_portal != NULL && sect->is_portal[*i] != -1)
		color = 0xFFFFFF;
	else
		color = 0xFF0000;
	return (color);
}

void				line(t_sdl *sdl, t_sect *sect, t_vertex *vertex, int col)
{
	t_vertex		start;
	t_vertex		end;

	start.x = vertex->x;
	start.y = vertex->y;
	if (vertex->next)
	{
		end.x = vertex->next->x;
		end.y = vertex->next->y;
		draw_line(sdl, start, end, col);
	}
	else if (sect->next)
	{
		end.x = sect->vertex->x;
		end.y = sect->vertex->y;
		draw_line(sdl, start, end, col);
	}
	else
		pixel_put(sdl, vertex->x, vertex->y, col);
}

void				render_sectors(t_edit *edit, t_sdl *sdl)
{
	int				i;
	int				color;
	t_sect			*sect;
	t_vertex		*vertex;

	sect = edit->sect;
	while (sect)
	{
		i = 0;
		vertex = sect->vertex;
		while (vertex && ++i)
		{
			color = get_color(sect, &i);
			line(sdl, sect, vertex, color);
			vertex = vertex->next;
		}
		sect = sect->next;
	}
}

void				display_points(t_sdl *sdl, SDL_Surface *bmp, t_point *oint)
{
	t_point			*point;

	point = oint;
	while (point)
	{
		draw_bmp(sdl, bmp,
				point->position.y - bmp->h / 2,
				point->position.x - bmp->w / 2);
		point = point->next;
	}
}

void				data_render(t_edit *edit)
{
	t_sdl			*sdl;

	sdl = edit->sdl;
	render_sectors(edit, sdl);
	if (edit->bind_points[0].x != -1 && edit->bind_points[1].x == -1)
		pixel_put(sdl, edit->bind_points[0].x,
				edit->bind_points[0].y, 0x00FF00);
	if (edit->player.current_sect != -1)
		draw_bmp(edit->sdl, edit->obj[2],
				edit->player.position.y - edit->obj[2]->h / 2,
				edit->player.position.x - edit->obj[2]->w / 2);
	display_points(sdl, edit->obj[1], edit->enemy);
	display_points(sdl, edit->obj[0], edit->objects);
}
