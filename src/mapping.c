/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:13:34 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/30 14:13:37 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_get_pixel(SDL_Surface *texture, int32_t x, int32_t y)
{
	int32_t	*get_pixel;

	get_pixel = texture->pixels + y * texture->pitch +
	x * texture->format->BytesPerPixel;
	return (*get_pixel);
}

t_rgb		ft_get_pixel_floor(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, double dd, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
		double	dx, dy, dist, diff;
	t_vertex	k;
	t_rgb		rgb;


	//x = (int)((x * diff_x) * 1000) % m->texture[3]->h;
	//color = m->texture[2]->pixels + i * m->texture[2]->pitch +
	//y * m->texture[2]->format->BytesPerPixel;
	GET_COLOR(color, m->texture[3]->pixels, i, m->texture[3]->pitch, wall.y, m->texture[3]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[3]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb		ft_get_pixel_wall(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	static int32_t	buff = -1;
	static int32_t	col = 0xffffff;
	int32_t	i;
	double	diff_x;
	t_rgb 	rgb;

	//ray.camdist = ray.camdist;
	diff_x = 64.0 / (double)wall.wall_h_map;

	//i = (int)((x * diff_x) * 100) % m->texture[0]->h;
	SET_I(i, x, diff_x, m->texture[0]->h);
	rgb.b = (col << 16);
	rgb.g = (col << 8);
	rgb.r = (col);
	if (i != buff)
	{
	//	color = m->texture[0]->pixels + i * m->texture[0]->pitch +
	//	y * m->texture[0]->format->BytesPerPixel;
		GET_COLOR(color, m->texture[0]->pixels, i, m->texture[0]->pitch, y, m->texture[0]->format->BytesPerPixel);
		SDL_GetRGB(*color, m->texture[0]->format, &rgb.r, &rgb.g, &rgb.b);
		col = *color;
	}
	buff = i;
	return (rgb);
}

t_rgb		ft_get_pixel_border(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
	t_rgb 	rgb;

	ray.camdist = ray.camdist;
	diff_y = wall.border_b_h / (wall.diff_bord_bot > 0 ? wall.diff_bord_bot : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((x * diff_x) * 64) % m->texture[1]->w;
	//color = m->texture[1]->pixels + i * m->texture[1]->pitch +
	//y * m->texture[1]->format->BytesPerPixel;
	GET_COLOR(color, m->texture[1]->pixels, i, m->texture[1]->pitch, y, m->texture[1]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[1]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb		ft_get_pixel_border_top(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
	t_rgb 	rgb;
	
	ray.camdist = ray.camdist;
	diff_y = wall.border_t_h / (wall.diff_bord_top > 0 ? wall.diff_bord_top : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((x * diff_x) * 64) % m->texture[1]->w;
	//color = m->texture[1]->pixels + i * m->texture[1]->pitch +
	//y * m->texture[1]->format->BytesPerPixel;
	GET_COLOR(color, m->texture[1]->pixels, i, m->texture[1]->pitch, y, m->texture[1]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[1]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}