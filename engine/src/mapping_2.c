/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:08 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:11 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double			is_higher(t_heigth_wall wall)
{
	double		val;

	val = 20;
	if (wall.floor > 0)
		val = val / wall.floor;
	else if (wall.floor < 0)
		val = val * fabs(wall.floor);
	else if (wall.floor == 0)
		return (val);
	return (val);
}

t_rgb			ft_get_pixel_wall(t_main *m, t_heigth_wall wall,
						int32_t x, int32_t y)
{
	int32_t		*color;
	int32_t		i;
	double		diff_x;
	t_rgb		rgb;

	diff_x = 64.0 / (double)wall.wall_h_map;
	SET_I(i, x, diff_x, m->texture[m->sector[m->player.sector].textures.wall]->h);
	GET_COLOR(color, m->texture[m->sector[m->player.sector].textures.wall]->pixels, i, m->texture[m->sector[m->player.sector].textures.wall]->pitch,
			y, m->texture[m->sector[m->player.sector].textures.wall]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[m->sector[m->player.sector].textures.wall]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb			ft_get_pixel_border(t_main *m, t_ray ray,
						t_heigth_wall wall, int32_t *iter_arr)
{
	int32_t		*color;
	int32_t		i;
	double		diff_x;
	double		diff_y;
	t_rgb		rgb;

	diff_y = wall.border_b_h / (wall.diff_bord_bot > 0 ?
				wall.diff_bord_bot : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((iter_arr[0] * diff_x) * 256) % m->texture[1]->w;
	GET_COLOR(color, m->texture[1]->pixels, i, m->texture[1]->pitch,
			iter_arr[1], m->texture[1]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[1]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb			ft_get_pixel_border_top(t_main *m, t_ray ray,
						t_heigth_wall wall, int32_t *iter_arr)
{
	int32_t		*color;
	int32_t		i;
	double		diff_x;
	double		diff_y;
	t_rgb		rgb;

	diff_y = wall.border_t_h / (wall.diff_bord_top > 0 ?
				wall.diff_bord_top : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((iter_arr[0] * diff_x) * 256) % m->texture[1]->w;
	GET_COLOR(color, m->texture[1]->pixels, i, m->texture[1]->pitch,
			iter_arr[1], m->texture[1]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[1]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}
