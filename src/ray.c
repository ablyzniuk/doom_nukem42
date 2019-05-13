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
	ray->old_num_sect = ray->num_sect;
	ray->ray_start.x = m->player.pos.x;
	ray->ray_start.y = m->player.pos.y;
	ray->addlen = 0.0;
	ray->ray_deep = 0;
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
	if (ray->angle == 0 && ray->num_sect != 0)
			drawline(m, ray->ray_start.x, ray->ray_start.y, ray->ray_end.x, ray->ray_end.y);
	drawline(m, ray->wall_start.x, ray->wall_start.y, ray->wall_end.x, ray->wall_end.y);
}

void	ft_draw_map(t_main *m)
{
	t_ray	ray; // разные нужные переменные

	ray.w = 0;
	ray.len_ray = 50; //    добавить функию просчета длинны луча 
	
	while (ray.w < WIDTH)
	{
		ft_get_data_ray(m, &ray);
		ray.addlen = 0.0;
		ft_ray(m, ray);
		ray.w++;
	}
	//ft_draw_cam(m, len);
	SDL_Log("-------------- %d", m->player.sector);
}

void	ft_ray(t_main *m, t_ray ray)
{
	t_save_ray	sv_ray;

	ray.ray_deep++;
	ray.wall_sect = 0;
	ft_put_pixel(m, m->player.pos.x,m->player.pos.y, 0x0000ff);
	while (ray.wall_sect < m->sector[ray.num_sect].vertex_arr_len)
	{
		ft_get_array_wall(m, &ray);
		ray.intersec = ft_intersection(ray.ray_start, ray.ray_end, ray.wall_start, ray.wall_end);
		if (ray.intersec.z != -1)
		{
			ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray;
			if (ray.angle != 0.0)
				ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray * cos(ray.angle);
			ft_drawscreen(m, ray);
		}
		
		if (ray.intersec.z != -1 && m->sector[ray.num_sect].transit[ray.wall_sect] != -1 && ray.ray_deep < 30
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
			sv_ray.sv_pos.x = ray.ray_start.x;
			sv_ray.sv_pos.y = ray.ray_start.y;
			ray.ray_start.x = ray.intersec.x * ray.vx;
			ray.ray_start.y = ray.intersec.y * ray.vy;
			ft_ray(m, ray);
			ray.ray_end.x = ray.ray_end.x;
			ray.ray_end.y = ray.ray_end.y;
			ray.num_sect = ray.old_num_sect;
			ray.old_num_sect = sv_ray.sv_old_sect;
			ray.ray_start.x = sv_ray.sv_pos.x;
			ray.ray_start.y = sv_ray.sv_pos.y;
		}
	
		ray.wall_sect++;
	}
}
//		int		k;
//		int		buff;
//		double		posx;
//		double		posy;
//		t_vertex	buffray;
//
//		k = 0;
//		ray.wall_sect = 0;
//
//		//if (ray.angle == 0.0)
//	//	if (ray.w >= 300 && ray.w <= 310)
//		while (ray.wall_sect < 4)
//		{
//			// последняя точка сзязана с первой
//			k = ray.wall_sect + 1;
//			if (k == 4)
//				k = 0;
//			//ищем пересечение луча и стенки
//		//	SDL_Log("%d \n", ray.num_sect);
//			ray.intersec = ft_intersection(ray.raystart, ray.ray, m->vertex[m->sector[ray.num_sect]->vertex[ray.wall_sect]], m->vertex[m->sector[ray.num_sect]->vertex[k]]);
//				if (ray.intersec.z != -1)
//				{
//					// как далеко попаданиеs
//					ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray;
//					//фикс рыбьего глаза
//					if (ray.angle != 0.0)
//						ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray * cos(ray.angle);
//
//					if (m->sector[ray.num_sect]->typewall[ray.wall_sect] == -1)
//						drawscreen(m, ray.w,
//						ray.camdist,
//						m->sector[ray.num_sect]->heigth.cell - m->sector[ray.num_sect]->heigth.floor,
//						ray.num_sect);
//					else if (m->sector[m->sector[ray.num_sect]->typewall[ray.wall_sect]]->heigth.floor != m->sector[ray.num_sect]->heigth.floor)
//						drawscreen(m, ray.w,
//						ray.camdist,
//						abs(m->sector[m->sector[ray.num_sect]->typewall[ray.wall_sect]]->heigth.floor - m->sector[ray.num_sect]->heigth.floor),
//						ray.num_sect);
//				}
//				if (ray.intersec.z != -1 && m->sector[ray.num_sect]->typewall[ray.wall_sect] != -1)
//				{
//					//SDL_Log("Check\n");
//					buffray.x = ray.ray.x;
//					buffray.y = ray.ray.y;
//
//					ray.ray.x = ray.intersec.x + ray.len_ray * ray.vx;
//					ray.ray.y = ray.intersec.y + ray.len_ray * ray.vy;
//					buff = ray.num_sect;
//					ray.num_sect = m->sector[ray.num_sect]->typewall[ray.wall_sect];
//					ray.addlen += ray.intersec.z;
//
//					posx = ray.raystart.x;
//					posy = ray.raystart.y;
//					ray.raystart.x = ray.intersec.x + 0.00001 * ray.vx;
//					ray.raystart.y = ray.intersec.y + 0.00001 * ray.vy;
//					ft_ray(m, ray);
//					ray.ray.x = buffray.x;
//					ray.ray.y = buffray.y;
//					ray.num_sect = buff;
//					ray.raystart.x = posx;
//					ray.raystart.y = posy;
//				}
//			ray.wall_sect++;
//		}
//		ft_draw_cam(m, 10);
