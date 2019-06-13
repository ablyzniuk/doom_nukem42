/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:37:21 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 13:37:22 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_draw_cam(t_main *m)
{
	drawline(m, 0, m->player.ecvator, WIDTH, m->player.ecvator);
}

void	ft_get_data_ray(t_main *m, t_ray *ray)
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

void	ft_get_array_wall(t_main *m, t_ray *ray)
{
	size_t	k;

	if (ray->wall_sect == 0)
		k = m->sector[ray->num_sect].vertex_arr_len - 1;
	else
		k = ray->wall_sect - 1;
	ray->wall_start.x = m->sector[ray->num_sect].vertex[k][1];
	ray->wall_start.y = m->sector[ray->num_sect].vertex[k][0];
	ray->wall_end.x = m->sector[ray->num_sect].vertex[ray->wall_sect][1];
	ray->wall_end.y = m->sector[ray->num_sect].vertex[ray->wall_sect][0];
}

void	ft_draw_map(t_main *m)
{
	t_ray	ray; // разные нужные переменные

	ray.w = 0;
	ray.len_ray = 1000; //    добавить функию просчета длинны луча 
	
	while (ray.w < WIDTH)
	{
		ft_get_data_ray(m, &ray);
		ray.addlen = 0.0;
		ft_ray(m, ray);
		ray.w++;
	}
	//ft_draw_cam(m, len);
//	SDL_Log("-------------- %d", m->player.sector);
}

double	ft_get_len_wall(t_vertex start, t_vertex end)
{
	return (ft_dist_cord(start.x, start.y, end.x, end.y));
}

void	ft_ray(t_main *m, t_ray ray)
{
	t_save_ray	sv_ray;

	ray.ray_deep++;
	ray.wall_sect = 0;
	while (ray.wall_sect < m->sector[ray.num_sect].vertex_arr_len)
	{
		ft_get_array_wall(m, &ray);
		ray.intersec = ft_intersection(ray.ray_start, ray.ray_end, ray.wall_start, ray.wall_end);
		if (ray.intersec.z != -1)
		{
			ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray;
			if (ray.angle != 0.0)
				ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray * cos(ray.angle);
			ray.next_sect = m->sector[ray.num_sect].transit[ray.wall_sect];
			ray.wall_len = ft_get_len_wall(ray.wall_start, ray.wall_end);
			ray.wall_len_ray = ft_get_len_wall(ray.wall_start, ray.intersec);
			ft_drawscreen(m, ray);
			if (ray.angle == 0.0)
				m->debug.wall = ray.wall_sect;
		}
		if (ray.intersec.z != -1 && m->sector[ray.num_sect].transit[ray.wall_sect] != -1 && ray.ray_deep < 32
		&& m->sector[ray.num_sect].transit[ray.wall_sect] != ray.old_num_sect)
		{
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
		ray.wall_sect++;
	}
}