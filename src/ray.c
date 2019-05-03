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

// рисуем рагуль 
void	ft_draw_cam(t_main *m, int len)
{
	t_ray ray;

	ray.ancos = cos((m->player.angle.hor) * M_PI / ANG);
	ray.ansin = sin((m->player.angle.hor) * M_PI / ANG);
	ray.vx = VECX * ray.ancos - VECY * ray.ansin;
	ray.vy = VECX * ray.ansin + VECY * ray.ancos;
	ray.x = m->player.pos.x + len * ray.vx;
	ray.y = m->player.pos.y + len * ray.vy;
	drawline(m, ray.y, ray.x, m->player.pos.y, m->player.pos.x);
	ray.ancos = cos((m->player.angle.hor - 30) * M_PI / ANG);
	ray.ansin = sin((m->player.angle.hor - 30) * M_PI / ANG);
	ray.vx = VECX * ray.ancos - VECY * ray.ansin;
	ray.vy = VECX * ray.ansin + VECY * ray.ancos;
	ray.x = m->player.pos.x + len * ray.vx;
	ray.y = m->player.pos.y + len * ray.vy;
	drawline(m, ray.y, ray.x, m->player.pos.y, m->player.pos.x);
	ray.ancos = cos((m->player.angle.hor + 30) * M_PI / ANG);
	ray.ansin = sin((m->player.angle.hor + 30) * M_PI / ANG);
	ray.vx = VECX * ray.ancos - VECY * ray.ansin;
	ray.vy = VECX * ray.ansin + VECY * ray.ancos;
	ray.x = m->player.pos.x + len * ray.vx;
	ray.y = m->player.pos.y + len * ray.vy;
	drawline(m, ray.y, ray.x, m->player.pos.y, m->player.pos.x);
	//drawline(m, 0, m->player.ecvator, WIDTH, m->player.ecvator);

}


// raycast
void	ft_draw_map(t_main *m)
{
	int		w; // текущий x
	t_ray	ray; // разные нужные переменные



	w = 0;
	ray.len_ray = 200;
	
	while (w < WIDTH)
	{
		ray.angle = -atan((HALFWIDTH - w) / DIST); // считаем правильный угол луча

		//кос син
		ray.ancos = cos((m->player.angle.hor) * M_PI / ANG + ray.angle);
		ray.ansin = sin((m->player.angle.hor) * M_PI / ANG + ray.angle);
		// вращаем вектор
		ray.vx = VECX * ray.ancos - VECY * ray.ansin;
		ray.vy = VECX * ray.ansin + VECY * ray.ancos;
		//находим кординаты второй точки луча
		ray.ray.x = m->player.pos.x + ray.len_ray * ray.vx;
		ray.ray.y = m->player.pos.y + ray.len_ray * ray.vy;
		//
		//номер точки в секторе
		ray.wall_sect = 0;
		ray.num_sect = m->player.sector;
		ray.w = w;
		ray.raystart.x = m->player.pos.x;
		ray.raystart.y = m->player.pos.y;
		ray.addlen = 0.0;
		ft_ray(m, ray);
		w++;
	}
	//ft_draw_cam(m, len);
	SDL_Log("-------------- %d", m->player.sector);
}

void	ft_ray(t_main *m, t_ray ray)
{
		static int 	flag = 0;
		int		k;
		int		he;
		int		buff;
		double		posx;
		double		posy;
		t_vertex	buffray;
		int			buffwallsect;

		k = 0;
		ray.wall_sect = 0;

		while (ray.wall_sect < 4)
		{
			// последняя точка сзязана с первой
			k = ray.wall_sect + 1;
			if (k == 4)
				k = 0;
			he = 0;
			//ищем пересечение луча и стенки
		
			ray.intersec = ft_intersection(ray.raystart, ray.ray, m->vertex[m->sector[ray.num_sect]->vertex[ray.wall_sect]], m->vertex[m->sector[ray.num_sect]->vertex[k]]);
		
				if (ray.intersec.z != -1 && m->sector[ray.num_sect]->typewall[ray.wall_sect] == -1)
				{
					// как далеко попадание
					
					ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray;

					//фикс рыбьего глаза
					
					if (ray.angle != 0.0)
						ray.camdist = (ray.intersec.z + ray.addlen) * ray.len_ray * cos(ray.angle);
					he = 1;
					if (flag != ray.num_sect)
						drawscreen(m, ray.w, ray.camdist, 1, ray.num_sect);
					else
						drawscreen(m, ray.w, ray.camdist, 0, ray.num_sect);
					if (ray.angle == 0.0)
						SDL_Log("|%f|", ray.camdist);
					flag = ray.wall_sect;
				}
				else if (ray.intersec.z != -1 && m->sector[ray.num_sect]->typewall[ray.wall_sect] != -1)
				{
					buffray = ray.ray;

					ray.intersec.x = ray.intersec.x + 0.00000001 * ray.vx;
					ray.intersec.y = ray.intersec.y + 0.00000001 * ray.vy;	
					ray.ray.x = ray.intersec.x + ray.len_ray * ray.vx;
					ray.ray.y = ray.intersec.y + ray.len_ray * ray.vy;
					buff = ray.num_sect;
					SDL_Log("%d\n", m->sector[ray.num_sect]->typewall[ray.wall_sect]);
					ray.num_sect = m->sector[ray.num_sect]->typewall[ray.wall_sect];
					ray.addlen = ray.intersec.z;
				
					posx = ray.raystart.x;
					posy = ray.raystart.y;
					ray.raystart.x = ray.intersec.x;
					ray.raystart.y = ray.intersec.y;

					ft_ray(m, ray);
					ray.ray = buffray;
					ray.num_sect = buff;
					ray.raystart.x = posx;
					ray.raystart.y = posy;
				}
			ray.wall_sect++;
		}
}