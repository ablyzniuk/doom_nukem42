/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:08:05 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/12 16:08:06 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_rgb	ft_set_fog(t_rgb rgb, t_ray ray)
{
	int	r;
	int	g;
	int	b;

	//r = rgb.r - (rgb.r / 100.0) * ray.camdist * FOG;
	//g = rgb.g - (rgb.g / 100.0) * ray.camdist * FOG;
	//b = rgb.b - (rgb.b / 100.0) * ray.camdist * FOG;
	SET_FOG(r, rgb.r, ray.camdist, ray.len_ray);
	SET_FOG(g, rgb.g, ray.camdist, ray.len_ray);
	SET_FOG(b, rgb.b, ray.camdist, ray.len_ray);
	if (r > 0 && r < rgb.r)
		rgb.r = r;
	else
		rgb.r = 0;
	if (g > 0 && g < rgb.r)
		rgb.g =g;
	else
		rgb.g = 0;
	if (g > 0 && g < rgb.r)
		rgb.b = b;
	else
		rgb.b = 0;
	return (rgb);
}

t_rgb	ft_set_fog_floor(t_rgb rgb, t_ray ray, t_heigth_wall wall, int32_t x)
{
	int		r;
	static int32_t	x_old = 0;
	int		g;
	int		b;
	double	dist;
	double	diff;

	if (x == wall.floor_h.floor_h - 1)
		x += x_old;
	dist = ray.camdist - ray.camdist_old;
	diff = ray.camdist / wall.floor_h.floor_h;
	dist = ray.camdist - diff * x;
	//diff = 
	SET_FOG(r, rgb.r, ray.camdist, ray.len_ray);
	SET_FOG(g, rgb.g, ray.camdist, ray.len_ray);
	SET_FOG(b, rgb.b, ray.camdist, ray.len_ray);
	if (r > 0 && r < rgb.r)
		rgb.r = r;
	else
		rgb.r = 0;
	if (g > 0 && g < rgb.r)
		rgb.g = g;
	else
		rgb.g = 0;
	if (g > 0 && g < rgb.r)
		rgb.b = b;
	else
		rgb.b = 0;
	x_old = x;
	return (rgb);
}

t_rgb	ft_set_fog_ceil(t_rgb rgb, t_ray ray, t_heigth_wall wall, int32_t x)
{
	int		r;
	static int32_t	x_old = 0;
	int		g;
	int		b;
	double	dist;
	double	diff;

	if (x == wall.floor_h.floor_h - 1)
		x += x_old;
	dist = ray.camdist - ray.camdist_old;
	diff = ray.camdist / wall.ceil_h.ceil_h;
	dist = ray.camdist - diff * x;
	//diff = 
	SET_FOG(r, rgb.r, dist, ray.len_ray);
	SET_FOG(g, rgb.g, dist, ray.len_ray);
	SET_FOG(b, rgb.b, dist, ray.len_ray);
	if (r > 0 && r < rgb.r)
		rgb.r = r;
	else
		rgb.r = 0;
	if (g > 0 && g < rgb.r)
		rgb.g = g;
	else
		rgb.g = 0;
	if (g > 0 && g < rgb.r)
		rgb.b = b;
	else
		rgb.b = 0;
	x_old = x;
	return (rgb);
}