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
	drawline(m, 0, m->player.ecvator, WIDTH, m->player.ecvator);

}


// raycast
void	ft_draw_map(t_main *m)
{
	int		w; // текущий x
	int		k;	//штука
	t_ray	ray; // разные нужные переменные
	int		len; // длина луч. Добавить расчет длинны
	int		he;
	static int 	flag;

	w = 0;
	len = 200;
	flag = 0;
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
		ray.x = m->player.pos.x + len * ray.vx;
		ray.y = m->player.pos.y + len * ray.vy;
		//
		ray.ray.x = ray.x;
		ray.ray.y = ray.y;
		//номер точки в секторе
		ray.num_sect = 0;
		while (ray.num_sect < 4)
		{
			// последняя точка сзязана с первой
			k = ray.num_sect + 1;
			if (k == 4)
				k = 0;
			he = 0;
			//ищем пересечение луча и стенки
			ray.intersec = ft_intersection(m->player.pos, ray.ray, m->vertex[m->sector->vertex[ray.num_sect]], m->vertex[m->sector->vertex[k]]);
		
			if (ray.intersec.z != -1)
			{
				// как далеко попадание
				
				ray.camdist = ray.intersec.z * len;

				//фикс рыбьего глаза
				
				if (ray.angle != 0.0)
					ray.camdist = ray.intersec.z * len * cos(ray.angle);
				he = 1;
				if (flag != ray.num_sect)
					drawscreen(m, w, ray.camdist, 1);
				else
					drawscreen(m, w, ray.camdist, 0);
				if (ray.angle == 0.0)
					SDL_Log("|%f|", ray.camdist);
				flag = ray.num_sect;
			}
			ray.num_sect++;
		}
		w++;
	}
	ft_draw_cam(m, len);
	SDL_Log("--------------");
}
