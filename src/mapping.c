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

int32_t		ft_get_pixel_wall(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;

	ray.camdist = ray.camdist;
	diff_y = wall.wall_h_map;
	diff_x = 64 / diff_y;
	i = (int)((x * diff_x) * 100) % m->texture[0]->w;
	color = m->texture[0]->pixels + i * m->texture[0]->pitch +
	y * m->texture[0]->format->BytesPerPixel;
	return (*color);
}

int32_t		ft_get_pixel_border(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;

	ray.camdist = ray.camdist;
	diff_y = wall.border_b_h / (wall.diff_bord_bot > 0 ? wall.diff_bord_bot : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((x * diff_x) * 64) % m->texture[1]->w;
	color = m->texture[1]->pixels + i * m->texture[1]->pitch +
	y * m->texture[1]->format->BytesPerPixel;
	return (*color);
}

int32_t		ft_get_pixel_border_top(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;

	ray.camdist = ray.camdist;
	diff_y = wall.border_t_h / (wall.diff_bord_top > 0 ? wall.diff_bord_top : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((x * diff_x) * 64) % m->texture[1]->w;
	color = m->texture[1]->pixels + i * m->texture[1]->pitch +
	y * m->texture[1]->format->BytesPerPixel;
	return (*color);
}