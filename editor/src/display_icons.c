/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_icons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:08:50 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:24 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			draw_bmp(t_sdl *sdl, SDL_Surface *bmp, int win_y, int win_x)
{
	int			x;
	int			y;
	int			*color;

	y = -1;
	while (++y < bmp->h)
	{
		x = -1;
		while (++x < bmp->w)
		{
			color = bmp->pixels + y * bmp->pitch +
				x * bmp->format->BytesPerPixel;
			if (*color != ~0xFF0F00)
				pixel_put(sdl, win_x + x, win_y + y, *color);
		}
	}
}

void			icons_render(t_edit *edit, SDL_Surface **bmp, t_sdl *sdl)
{
	int			i;
	int			active;

	i = -1;
	while (++i < NUM_TEX_P)
		draw_bmp(sdl, bmp[i], edit->pos_start[i][1], edit->pos_start[i][0]);
	active = edit->sett;
	if (active == 0)
	{
		if (edit->sect_is_closed == 0)
			draw_bmp(sdl, edit->bmp_a[NUM_TEX_A - 1],
					edit->pos_start[0][1], edit->pos_start[0][0]);
		else
			draw_bmp(sdl, edit->bmp_a[0],
					edit->pos_start[0][1], edit->pos_start[0][0]);
	}
	else
		draw_bmp(sdl, edit->bmp_a[active],
				edit->pos_start[active][1], edit->pos_start[active][0]);
}

void			background_render(t_edit *edit)
{
	int			y;
	t_vertex	start;
	t_vertex	end;
	int			color;

	y = 0;
	color = 0xFFBF00;
	while (y <= WIN_H)
	{
		if (edit->sett == textures && y >= edit->y_tex)
			color = 0x222D65;
		start.x = edit->x_bounds;
		start.y = y;
		end.x = WIN_W;
		end.y = y;
		draw_line(edit->sdl, start, end, color);
		y++;
	}
}
