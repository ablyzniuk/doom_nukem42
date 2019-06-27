/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:16 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/27 00:00:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				ft_get_pixel(SDL_Surface *texture, int32_t x, int32_t y)
{
	int32_t		*get_pixel;

	get_pixel = texture->pixels + y * texture->pitch +
		x * texture->format->BytesPerPixel;
	return (*get_pixel);
}

inline double_t	get_dist(void)
{
	return (((double)WIDTH / 2) /
			(tan((double)FIELD_OF_VIEW / 2.0 * M_PI / 180.0)));
}

inline double_t	get_dist_ceil(void)
{
	return (((double)WIDTH * 2) /
			(tan((double)FIELD_OF_VIEW / 2.0 * M_PI / 180.0)));
}

t_rgb			ft_get_pixel_ceil(t_main *m, t_ray ray, t_heigth_wall wall)
{
	t_iter		iter;
	int32_t		*color;
	t_rgb		rgb;
	double		vector[2];
	int8_t		tex_val;

	iter.dist2 = get_dist_ceil();
	iter.dist = (((double)(m->sector[ray.num_sect].heigth.cell -
	m->player.p_he) * iter.dist2) / FT_ABS((m->player.ecvator -
			wall.ceil_h.start)));
	iter.dist /= cos(ray.angle);
	vector[0] = ray.vx * iter.dist;
	vector[1] = ray.vy * iter.dist;
	iter.dx = fabs(m->player.pos.x * (double)(wall.ceil -
			m->player.p_he) + vector[0]);
	iter.dy = fabs(m->player.pos.y * (double)(wall.ceil -
			m->player.p_he) + vector[1]);
	tex_val = m->sector[ray.num_sect].textures.celling;
	GET_COLOR(color, m->texture[tex_val]->pixels,
			(int)(iter.dx * 50.0) % m->texture[tex_val]->w,
			m->texture[tex_val]->pitch,
			(int)(iter.dy * 50.0) % m->texture[tex_val]->h,
			m->texture[tex_val]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[tex_val]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb			ft_get_pixel_floor(t_main *m, t_ray ray,
						t_heigth_wall wall)
{
	t_iter		iter;
	int32_t		*color;
	t_rgb		rgb;
	double		vector[2];
	int8_t		tex_val;

	iter.dist2 = get_dist();
	iter.dist = (((double)(m->player.p_he) * iter.dist2) /
					FT_ABS((m->player.ecvator - wall.floor_h.start)));
	iter.dist /= cos(ray.angle);
	vector[0] = ray.vx * iter.dist;
	vector[1] = ray.vy * iter.dist;
	iter.dx = fabs(m->player.pos.x * (double)(7.0 + wall.floor) + vector[0]);
	iter.dy = fabs(m->player.pos.y * (double)(7.0 + wall.floor) + vector[1]);
	tex_val = m->sector[ray.num_sect].textures.floor;
	GET_COLOR(color, m->texture[tex_val]->pixels,
			(int)(iter.dx * is_higher(wall)) % m->texture[tex_val]->w,
			m->texture[tex_val]->pitch,
			(int)(iter.dy * is_higher(wall)) % m->texture[tex_val]->h,
			m->texture[tex_val]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[tex_val]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}
