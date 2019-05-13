/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:36:20 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 15:36:22 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
//ставим пиксель
void	ft_put_pixel(t_main *m, int x, int y, int pixel)
{
	int		*target_pixel;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT - 1)
		return ;
	target_pixel = m->sdl.winsurface->pixels + y * m->sdl.winsurface->pitch + x *
	m->sdl.winsurface->format->BytesPerPixel;
	*target_pixel = pixel;
}

//берем пиксель с текстуры / потом
int		ft_get_pixel(SDL_Surface *texture, int x, int y)
{
	int	*get_pixel;

	get_pixel = texture->pixels + y * texture->pitch +
	x * texture->format->BytesPerPixel;
	return (*get_pixel);
}

// брезенхем
void	drawline(t_main *m, int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;
	ft_put_pixel(m, x2, y2, 0xff00ff);
	while(x1 != x2 || y1 != y2) 
   {
	   ft_put_pixel(m, x1, y1, 0xff00ff);
		const int error2 = error * 2;
		//
		if(error2 > -deltaY) 
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX) 
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

//рисуем сегмент стены 

void	ft_drawscreen(t_main *m, t_ray ray)
{
	int32_t		start;
	int32_t		end;
	int32_t		he_wall;
	int			color;
	double		diff;
	double		hesect;
	double		dhe;
	int32_t		flag;
	static int32_t old_start = 0;
	static int32_t old_end = 0;
	static int32_t old_w = -1;
	static int32_t buffer = HEIGHT;

	flag = 0;
	he_wall = DIST / ray.camdist;
	hesect = m->sector[ray.num_sect].heigth.cell - m->sector[ray.num_sect].heigth.floor;
	diff = he_wall / hesect;
	dhe = m->sector[ray.num_sect].heigth.floor - m->sector[m->player.sector].heigth.floor;
	end = m->player.ecvator + he_wall - dhe * diff;
	start = end - HE_P * (m->sector[ray.num_sect].heigth.cell
		- m->sector[ray.num_sect].heigth.floor) / ray.camdist;

	if (old_w != ray.w)
	{
		buffer = HEIGHT;
		while (buffer >= end)
		{
			ft_put_pixel(m, ray.w, buffer, 0xffff00);
			buffer--;
			flag = 1;
		}
		buffer = end;
	}
	if (ray.old_num_sect != ray.num_sect)
	{
		if (m->sector[ray.old_num_sect].heigth.floor == m->sector[ray.num_sect].heigth.floor)
		{	
			while (buffer > end)
			{
			//	SDL_Log("|%d %d|\n", end, old_start);
				ft_put_pixel(m, ray.w, buffer, 0xff0000);
				buffer--;
				flag = 1;
			}
			buffer = end;
		}
	}
	if (m->sector[ray.num_sect].transit[ray.wall_sect] == -1)
		while (start < end)
		{
			ft_put_pixel(m, ray.w, start, 0xffff00 / (ray.num_sect + 1));
			start++;
			flag = 1;
		}
	if (flag == 1)
	{
		old_start = start;
		old_end = end;
	}
	old_w = ray.w;
}
//	int start;
//	int endstart;
//	int he;
//	int	buff;
//	static	int drawstart = HEIGHT;
//	static	int oldw = 0;
//
//	if (oldw != x)
//		drawstart = HEIGHT;
//	// считаем начало стены;
//	he = DIST / z;
//	endstart = m->player.ecvator + he;
//	// высота стены
//	start = endstart - HE_P * (heigth) / z;
//	buff = start;
//	if (endstart > HEIGHT)
//		endstart = HEIGHT;
//	//SDL_Log("|%d %d | %d|\n", start, endstart, drawstart);
//	if (oldw != x)
//		ft_draw_floor(m, endstart, HEIGHT, x);
//	if (m->sector[sect]->heigth.floor != m->sector[m->player.sector]->heigth.floor)
//	{
//		ft_draw_floor(m, start, drawstart, x);
//		drawstart = buff;
//	}
//	if (sect != m->player.sector && m->sector[sect]->heigth.floor == m->sector[m->player.sector]->heigth.floor)
//	{
//		ft_draw_floor(m, endstart, drawstart, x);
//	}
//	while (start < endstart && start < drawstart)
//	{
//		ft_put_pixel(m, x, start, m->sector[sect]->color);
//		start++;
//	}
//	oldw = x;
//	if (buff < drawstart)
//		drawstart = buff;
