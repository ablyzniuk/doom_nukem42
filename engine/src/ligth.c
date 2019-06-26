/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:08:05 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:05 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_rgb			ft_set_fog(t_rgb rgb, t_ray ray)
{
	int			r;
	int			g;
	int			b;

	SET_FOG(r, rgb.r, ray.camdist, ray.len_ray);
	SET_FOG(g, rgb.g, ray.camdist, ray.len_ray);
	SET_FOG(b, rgb.b, ray.camdist, ray.len_ray);
	if (r > 0 && r < rgb.r)
		rgb.r = r;
	else
		rgb.r = 0;
	if (g > 0 && g < rgb.g)
		rgb.g = g;
	else
		rgb.g = 0;
	if (b > 0 && b < rgb.b)
		rgb.b = b;
	else
		rgb.b = 0;
	return (rgb);
}

t_rgb			ft_set_fog_floor(t_rgb rgb, t_ray ray,
						t_heigth_wall wall, int32_t x)
{
	static int32_t	x_old = -1;
	int				r;
	int				g;
	int				b;
	double			dist;

	if (x == wall.floor_h.floor_h - 1)
		x += x_old;
	dist = x * ray.len_ray / 1000;
	SET_FOG(r, rgb.r, dist, ray.len_ray);
	SET_FOG(g, rgb.g, dist, ray.len_ray);
	SET_FOG(b, rgb.b, dist, ray.len_ray);
	rgb.r = (r > 0 && r < rgb.r) ? r : 0;
	rgb.g = (g > 0 && g < rgb.r) ? g : 0;
	rgb.b = (g > 0 && g < rgb.r) ? b : 0;
	x_old = x;
	return (rgb);
}

t_rgb			ft_set_fog_ceil(t_rgb rgb, t_ray ray,
						t_heigth_wall wall, int32_t x)
{
	static int32_t	x_old = -1;
	int				r;
	int				g;
	int				b;
	double			dist;

	if (x == wall.ceil_h.ceil_h - 1)
		x += x_old;
	dist = x * ray.len_ray / 1000;
	SET_FOG(r, rgb.r, dist, ray.len_ray);
	SET_FOG(g, rgb.g, dist, ray.len_ray);
	SET_FOG(b, rgb.b, dist, ray.len_ray);
	rgb.r = (r > 0 && r < rgb.r) ? r : 0;
	rgb.g = (g > 0 && g < rgb.r) ? g : 0;
	rgb.b = (g > 0 && g < rgb.r) ? b : 0;
	x_old = x;
	return (rgb);
}
