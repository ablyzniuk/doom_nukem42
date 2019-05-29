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

	save = wall.floor_h.start;
	while (wall.floor_h.start < wall.floor_h.end && wall.floor_h.start < buf->buffer_draw_bot)
	{
		ft_put_pixel(m, ray.w, wall.floor_h.start, 0xffffff / (ray.num_sect + 5));
		wall.floor_h.start++;
	}
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ? save : buf->buffer_draw_bot;
}

void	ft_draw_wall(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t	save;

	if (wall.start < buf->buffer_draw_top)
	{
		wall.start = buf->buffer_draw_top;
		buf->buffer_draw_top = wall.start;
	}
	save = wall.start;
	while (wall.start < wall.end && wall.start < buf->buffer_draw_bot)
	{
		ft_put_pixel(m, ray.w, wall.start, 0xffffff / (ray.num_sect + 2));
		wall.start++;
	}
	buf->buffer_draw_bot = save < buf->buffer_draw_bot ? save : buf->buffer_draw_bot;
}

void	ft_draw_cell(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t		sv_start;
	int32_t		sv_end;
	

}

void	ft_draw_border(t_main *m, t_ray ray, t_heigth_wall wall, t_buffer *buf)
{
	int32_t		save;
	
	if (wall.border_bot.flag == 1)
	{
		save = wall.border_bot.start;
		while (wall.border_bot.start < wall.border_bot.end && wall.border_bot.start < buf->buffer_draw_bot)
		{
			ft_put_pixel(m, ray.w, wall.border_bot.start, 0xffffff / (ray.num_sect + 7));
			wall.border_bot.start++;
		}
		buf->buffer_draw_bot = save < buf->buffer_draw_bot ? save : buf->buffer_draw_bot;
	}
	if (wall.border_top.flag == 1)
	{
		if (wall.border_top.start < buf->buffer_draw_top)
			wall.border_top.start = buf->buffer_draw_top;
		save = wall.border_top.end;
		while (wall.border_top.start < wall.border_top.end && wall.border_top.start < buf->buffer_draw_bot)
		{
			ft_put_pixel(m, ray.w, wall.border_top.start, 0xff0000);
			wall.border_top.start++;
		}
		buf->buffer_draw_top = save < buf->buffer_draw_top ? save : buf->buffer_draw_top;
	}
}