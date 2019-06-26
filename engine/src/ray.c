/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:37:21 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:19:05 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			k_ft_ray(t_main *m, t_ray ray)
{
	t_save_ray	sv_ray;

	sv_ray.sv_ray_end.x = ray.ray_end.x;
	sv_ray.sv_ray_end.y = ray.ray_end.y;
	ray.ray_end.x = ray.intersec.x + ray.len_ray * ray.vx;
	ray.ray_end.y = ray.intersec.y + ray.len_ray * ray.vy;
	sv_ray.sv_old_sect = ray.old_num_sect;
	ray.old_num_sect = ray.num_sect;
	ray.num_sect = m->sector[ray.old_num_sect].transit[ray.wall_sect];
	ray.addlen += ray.intersec.z;
	ray.camdist_old = ray.camdist;
	sv_ray.sv_pos.x = ray.ray_start.x;
	sv_ray.sv_pos.y = ray.ray_start.y;
	ray.ray_start.x = ray.intersec.x - 0.01 * ray.vx;
	ray.ray_start.y = ray.intersec.y - 0.01 * ray.vy;
	ft_ray(m, ray);
	ray.ray_end.x = sv_ray.sv_ray_end.x;
	ray.ray_end.y = sv_ray.sv_ray_end.y;
	ray.num_sect = ray.old_num_sect;
	ray.old_num_sect = sv_ray.sv_old_sect;
	ray.ray_start.x = sv_ray.sv_pos.x;
	ray.ray_start.y = sv_ray.sv_pos.y;
}

void			h_ft_ray(t_main *m, t_ray ray)
{
	if (ray.w == HALFWIDTH)
	{
		m->spr_data.pos.x = ray.intersec.x;
		m->spr_data.pos.y = ray.intersec.y;
		m->spr_data.vecx = ray.vx;
		m->spr_data.vecy = ray.vy;
	}
	ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray;
	if (ray.angle != 0.0)
		ray.camdist = (ray.intersec.z + ray.addlen) *
				ray.len_ray * cos(ray.angle);
	ray.next_sect = m->sector[ray.num_sect].transit[ray.wall_sect];
	ray.wall_len = ft_get_len_wall(ray.wall_start, ray.wall_end);
	ray.wall_len_ray = ft_get_len_wall(ray.wall_start, ray.intersec);
	ft_drawscreen(m, ray);
	if (ray.angle == 0.0)
		m->debug.wall = ray.wall_sect;
}

void			ft_ray(t_main *m, t_ray ray)
{
	ray.ray_deep++;
	ray.wall_sect = 0;
	while (ray.wall_sect < m->sector[ray.num_sect].vertex_arr_len)
	{
		ft_get_array_wall(m, &ray);
		ray.intersec = ft_intersection(ray.ray_start, ray.ray_end,
				ray.wall_start, ray.wall_end);
		if (ray.intersec.z != -1)
			h_ft_ray(m, ray);
		if (ray.intersec.z != -1 &&
				m->sector[ray.num_sect].transit[ray.wall_sect] != -1 &&
				ray.ray_deep < 32
				&& m->sector[ray.num_sect].transit[ray.wall_sect] !=
				ray.old_num_sect)
			k_ft_ray(m, ray);
		ray.wall_sect++;
	}
}
