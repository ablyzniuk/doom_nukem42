/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:03 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:28 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			pixel_put(t_sdl *sdl, int x, int y, int color)
{
	int			*pixel;
	SDL_Surface	*surface;

	surface = sdl->surface;
	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		pixel = surface->pixels + y * surface->pitch
			+ x * surface->format->BytesPerPixel;
		*pixel = color;
	}
}

void			draw_line(t_sdl *sdl, t_vertex start, t_vertex end, int color)
{
	t_line		line;

	line.delta_x = abs(end.x - start.x);
	line.delta_y = abs(end.y - start.y);
	line.sign_x = start.x < end.x ? 1 : -1;
	line.sign_y = start.y < end.y ? 1 : -1;
	line.error = line.delta_x - line.delta_y;
	pixel_put(sdl, end.x, end.y, color);
	while (start.x != end.x || start.y != end.y)
	{
		pixel_put(sdl, start.x, start.y, color);
		line.error2 = line.error * 2;
		if (line.error2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			start.x += line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			start.y += line.sign_y;
		}
	}
}

void			set_grid(t_edit *edit)
{
	int			x;
	int			y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pixel_put(edit->sdl, x, y, 0xFFFFFF);
			x += edit->zoom;
		}
		y += edit->zoom;
	}
}
