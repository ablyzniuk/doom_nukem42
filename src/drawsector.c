/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:19:09 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/06 12:19:11 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_draw_floor(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t	save;
	int32_t x, y;
	t_rgb	col;
	t_vertex k;
	double	dx, dy, dist, diff;
	static	int32_t w = -1;
	
	save = wall.floor_h.start;

	x = wall.floor_h.floor_h;
	//x = 0;
	col.r = 91;
		col.g = 26;
		col.b = 26;
	y = 0;
	while (wall.floor_h.start < wall.floor_h.end && wall.floor_h.start < buf->buffer_draw_bot)
	{
		col = ft_get_pixel_floor(m, ray, wall, x, y);
		if (m->setting.fog == 1 && 0)
			col = ft_set_fog_floor(col, ray, wall, x);
		ft_put_pixel_rgb(m, ray.w, wall.floor_h.start, col);
		wall.floor_h.start++;
		y++;
		x--;
	}
	w = ray.w;
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ? save : buf->buffer_draw_bot;
}

void	ft_draw_wall(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t	save;
	t_rgb	col;
	int32_t	x;
	int32_t	start;
	double	dx, dy;

	col.r = 255;
	col.g = 255;
	col.b = 255;
	dx = ray.wall_end.x - ray.wall_start.x;
	dy = ray.wall_end.y - ray.wall_start.y;
	x = 0;
	start = wall.start;
	while (start < buf->buffer_draw_top)
	{
		start++;
		x++;
	}
	save = wall.start;
	while (start < wall.end && start < buf->buffer_draw_bot)
	{
		col = ft_get_pixel_wall(m, ray, wall, x, abs(wall.y));
		if (m->setting.fog == 1)
			col = ft_set_fog(col, ray);
		ft_put_pixel_rgb(m, ray.w, start, col);
		start++;
		x++;
	}
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ? save : buf->buffer_draw_bot;
}

void	ft_draw_cell(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t	save;
	t_rgb	col;
	int32_t	x;

	x = 0;
	save = wall.ceil_h.start;
	while (wall.ceil_h.start < wall.ceil_h.end && wall.ceil_h.start <  buf->buffer_draw_bot)
	{
		col.r = 124;
		col.g = 75;
		col.b = 22;
		if (m->setting.fog == 1)
			col = ft_set_fog_ceil(col, ray, wall, x);
		ft_put_pixel_rgb(m, ray.w, wall.ceil_h.start, col);
		wall.ceil_h.start++;
		x++;
	}
	buf->buffer_draw_top = save > buf->buffer_draw_top ? save : buf->buffer_draw_top;

}

void	ft_draw_border(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t		save;
	int32_t		color;
	int32_t		x;
	t_rgb		col;

	color =  0xffFFFF;
	if (wall.border_bot.flag == 1)
	{
		x = 0;
		save = wall.border_bot.start;
		while (wall.border_bot.start < wall.border_bot.end && wall.border_bot.start < buf->buffer_draw_bot)
		{
			col = ft_get_pixel_border(m, ray, wall, x, abs(wall.y));
			if (m->setting.fog == 1)
				col = ft_set_fog(col, ray);
			ft_put_pixel_rgb(m, ray.w, wall.border_bot.start, col);
			x++;
			wall.border_bot.start++;
		}
		buf->buffer_draw_bot = save < buf->buffer_draw_bot ? save : buf->buffer_draw_bot;
	}
	if (wall.border_top.flag == 1)
	{
		x = 0;
		while (wall.border_top.start < buf->buffer_draw_top)
		{
			wall.border_top.start++;
			x++;
		}
		save = wall.border_top.end;
		while (wall.border_top.start < wall.border_top.end && wall.border_top.start < buf->buffer_draw_bot)
		{
			col = ft_get_pixel_border_top(m, ray, wall, x, abs(wall.y));
			if (m->setting.fog == 1)
				col = ft_set_fog(col, ray);
			ft_put_pixel_rgb(m, ray.w, wall.border_top.start, col);
			x++;
			wall.border_top.start++;
		}
		buf->buffer_draw_top = save > buf->buffer_draw_top ? save : buf->buffer_draw_top;
	}
}