/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:19:09 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/27 11:52:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void				ft_draw_floor(t_main *m, t_ray ray,
					t_heigth_wall wall, t_buffer *buf)
{
	static int32_t	w = -1;
	int32_t			save;
	t_rgb			col;
	double			x;

	save = wall.floor_h.start;
	x = ray.camdist - ray.addlen;
	col.r = 91;
	col.g = 26;
	col.b = 26;
	while (wall.floor_h.start < wall.floor_h.end
		&& wall.floor_h.start < buf->buffer_draw_bot)
	{
		col = ft_get_pixel_floor(m, ray, wall);
		ft_put_pixel_rgb(m, ray.w, wall.floor_h.start, col);
		wall.floor_h.start++;
	}
	w = ray.w;
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ?
								save : buf->buffer_draw_bot;
}

static int32_t		ft_draw_wall_iterator(t_iter *iter,
					t_buffer *buf, t_heigth_wall wall)
{
	iter->x = 0;
	iter->start = wall.start;
	while (iter->start < buf->buffer_draw_top)
	{
		iter->start++;
		iter->x++;
	}
	return (wall.start);
}

void				ft_draw_wall(t_main *m, t_ray ray,
						t_heigth_wall wall, t_buffer *buf)
{
	t_iter			iter;
	int32_t			save;
	t_rgb			col;
	int32_t			data_arr[2];

	col.r = 255;
	col.g = 255;
	col.b = 255;
	save = ft_draw_wall_iterator(&iter, buf, wall);
	while (iter.start < wall.end && iter.start < buf->buffer_draw_bot)
	{
		data_arr[0] = iter.x;
		data_arr[1] = abs(wall.y);
		col = ft_get_pixel_wall(m, wall, ray, data_arr);
		if (m->setting.fog == 1)
			col = ft_set_fog(col, ray);
		if (col.r != 0x00 && col.g != 0xF0 && col.b != 0xFF)
			ft_put_pixel_rgb(m, ray.w, iter.start, col);
		iter.start++;
		iter.x++;
	}
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ?
							save : buf->buffer_draw_bot;
}

void				ft_draw_cell(t_main *m, t_ray ray,
					t_heigth_wall wall, t_buffer *buf)
{
	int32_t			save;
	t_rgb			col;
	int32_t			x;

	x = 0;
	save = wall.ceil_h.start;
	while (wall.ceil_h.start < wall.ceil_h.end
			&& wall.ceil_h.start < buf->buffer_draw_bot)
	{
		col.r = 124;
		col.g = 75;
		col.b = 22;
		col = ft_get_pixel_ceil(m, ray, wall);
		ft_put_pixel_rgb(m, ray.w, wall.ceil_h.start, col);
		wall.ceil_h.start++;
		x++;
	}
	buf->buffer_draw_top = save > buf->buffer_draw_top ?
							save : buf->buffer_draw_top;
}
