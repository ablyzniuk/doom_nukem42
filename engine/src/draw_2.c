/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:01 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:04 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_put_pixel(t_main *m, int x, int y, int32_t pixel)
{
	int			*target_pixel;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT - 1)
		return ;
	target_pixel = m->sdl.winsurface->pixels + y *
			m->sdl.winsurface->pitch + x *
			m->sdl.winsurface->format->BytesPerPixel;
	*target_pixel = pixel;
}

void			ft_put_pixel_rgb(t_main *m, int x, int y, t_rgb col)
{
	int32_t		*target_pixel;
	int32_t		color;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT - 1)
		return ;
	target_pixel = m->sdl.winsurface->pixels + y *
			m->sdl.winsurface->pitch + x *
			m->sdl.winsurface->format->BytesPerPixel;
	color = SDL_MapRGB(m->texture[0]->format, col.r, col.g, col.b);
	*target_pixel = color;
}

void			drawline(t_main *m, t_vertex s, t_vertex e)
{
	t_line		line;

	line.delta_x = abs((int)((int)e.x - (int)s.x));
	line.delta_y = abs((int)((int)e.y - (int)s.y));
	line.sign_x = (int)s.x < (int)e.x ? 1 : -1;
	line.sign_y = (int)s.y < (int)e.y ? 1 : -1;
	line.error = line.delta_x - line.delta_y;
	ft_put_pixel(m, (int)e.x, (int)e.y, 0xff00ff);
	while ((int)s.x != (int)e.x || (int)s.y != (int)e.y)
	{
		ft_put_pixel(m, (int)s.x, (int)s.y, 0xff00ff);
		line.error2 = line.error * 2;
		if (line.error2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			s.x = (int)s.x + line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			s.y = (int)s.y + line.sign_y;
		}
	}
}

void			ft_get_wall_heigth(t_main *m, t_ray ray, t_heigth_wall *wall)
{
	wall->he_wall = DIST / ray.camdist;
	wall->he_sect = fabs(m->sector[ray.num_sect].heigth.cell -
			m->sector[ray.num_sect].heigth.floor);
	wall->diff = wall->he_wall / 10.0;
	wall->floor = m->sector[ray.num_sect].heigth.floor - m->player.pos.z;
	wall->ceil = m->sector[ray.num_sect].heigth.cell - m->player.pos.z;
	wall->end = m->player.ecvator + wall->diff *
			m->player.p_he - wall->diff * wall->floor * 2;
	wall->start = wall->end - wall->he_wall - wall->diff *
			wall->he_sect + wall->diff * wall->floor;
	wall->wall_h_map = abs(wall->end - wall->start);
}
