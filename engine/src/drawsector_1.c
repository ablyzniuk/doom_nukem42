/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsector_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:19:31 by ablizniu          #+#    #+#             */
/*   Updated: 2019/06/26 18:02:40 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_draw_border_border_bot_start(t_main *m, t_ray ray,
				t_heigth_wall *wall, t_buffer *buf)
{
	t_rgb		col;
	int32_t		iter_arr[2];
	int32_t		save;

	iter_arr[0] = 0;
	iter_arr[1] = wall->y;
	save = wall->border_bot.start;
	while (wall->border_bot.start < wall->border_bot.end &&
			wall->border_bot.start < buf->buffer_draw_bot)
	{
		col = ft_get_pixel_border(m, *wall, iter_arr, ray);
		if (m->setting.fog == 1)
			col = ft_set_fog(col, ray);
		if (col.r != 0x00 && col.g != 0xF0 && col.b != 0xFF)
			ft_put_pixel_rgb(m, ray.w, wall->border_bot.start, col);
		iter_arr[0]++;
		wall->border_bot.start++;
	}
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ?
								save : buf->buffer_draw_bot;
}

void			ft_draw_border_border_top_start(t_main *m, t_ray ray,
				t_heigth_wall *wall, t_buffer *buf)
{
	t_rgb		col;
	int32_t		iter_arr[2];
	int32_t		save;

	iter_arr[0] = 0;
	iter_arr[1] = wall->y;
	while (wall->border_top.start < buf->buffer_draw_top)
	{
		wall->border_top.start++;
		iter_arr[0]++;
	}
	save = wall->border_top.end;
	while (wall->border_top.start < wall->border_top.end &&
			wall->border_top.start < buf->buffer_draw_bot)
	{
		col = ft_get_pixel_border_top(m, *wall, iter_arr, ray);
		if (m->setting.fog == 1)
			col = ft_set_fog(col, ray);
		if (col.r != 0x00 && col.g != 0xF0 && col.b != 0xFF)
			ft_put_pixel_rgb(m, ray.w, wall->border_top.start, col);
		iter_arr[0]++;
		wall->border_top.start++;
	}
	buf->buffer_draw_top = save > buf->buffer_draw_top ?
							save : buf->buffer_draw_top;
}

void			ft_draw_border(t_main *m, t_ray ray,
						t_heigth_wall wall, t_buffer *buf)
{
	if (wall.border_bot.flag == 1)
		ft_draw_border_border_bot_start(m, ray, &wall, buf);
	if (wall.border_top.flag == 1)
		ft_draw_border_border_top_start(m, ray, &wall, buf);
}
