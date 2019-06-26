/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:20 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:27 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_draw_cam(t_main *m)
{
	t_vertex	s;
	t_vertex	e;

	s.x = 0;
	s.y = m->player.ecvator;
	e.x = WIDTH;
	e.y = m->player.ecvator;
	drawline(m, s, e);
}

void			ft_get_data_ray(t_main *m, t_ray *ray)
{
	ray->angle = -atan((HALFWIDTH - ray->w) / DIST);
	ray->ancos = cos((m->player.angle.hor) * M_PI / ANG + ray->angle);
	ray->ansin = sin((m->player.angle.hor) * M_PI / ANG + ray->angle);
	ray->vx = VECX * ray->ancos - VECY * ray->ansin;
	ray->vy = VECX * ray->ansin + VECY * ray->ancos;
	ray->ray_end.x = m->player.pos.x + ray->len_ray * ray->vx;
	ray->ray_end.y = m->player.pos.y + ray->len_ray * ray->vy;
	ray->wall_sect = 0;
	ray->num_sect = m->player.sector;
	ray->old_num_sect = -2;
	ray->ray_start.x = m->player.pos.x;
	ray->ray_start.y = m->player.pos.y;
	ray->addlen = 0.0;
	ray->ray_deep = 0;
	ray->camdist_old = 0;
}

void			ft_get_array_wall(t_main *m, t_ray *ray)
{
	size_t		k;

	if (ray->wall_sect == 0)
		k = m->sector[ray->num_sect].vertex_arr_len - 1;
	else
		k = ray->wall_sect - 1;
	ray->wall_start.x = m->sector[ray->num_sect].vertex[k][1];
	ray->wall_start.y = m->sector[ray->num_sect].vertex[k][0];
	ray->wall_end.x = m->sector[ray->num_sect].vertex[ray->wall_sect][1];
	ray->wall_end.y = m->sector[ray->num_sect].vertex[ray->wall_sect][0];
	if (ray->angle == 0 && ray->num_sect != 0)
	{
		drawline(m, ray->ray_start, ray->ray_end);
		ft_put_pixel(m, m->player.pos.x, m->player.pos.y, 0xff00ff);
	}
	drawline(m, ray->wall_start, ray->wall_end);
}

void			ft_draw_map(t_main *m)
{
	t_ray		ray;
	double		delta;

	ray.w = 0;
	delta = WIDTH / FIELD_OF_VIEW;
	ray.len_ray = 1000;
	ray.ancos = cos((m->player.angle.hor) * M_PI / ANG);
	ray.ansin = sin((m->player.angle.hor) * M_PI / ANG);
	ray.vx = VECX * ray.ancos - VECY * ray.ansin;
	ray.vy = VECX * ray.ansin + VECY * ray.ancos;
	while (ray.w < WIDTH)
	{
		ft_get_data_ray(m, &ray);
		m->spr_data.w[ray.w] = ray.w;
		m->spr_data.angle[ray.w] = (ray.angle * ANG / M_PI);
		ray.addlen = 0.0;
		ft_ray(m, ray);
		m->spr_data.dist[ray.w] = ray.camdist;
		ray.w++;
	}
	ft_sprite(m);
}

double			ft_get_len_wall(t_vertex start, t_vertex end)
{
	return (ft_dist_cord(start.x, start.y, end.x, end.y));
}
