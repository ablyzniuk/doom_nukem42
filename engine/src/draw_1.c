/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:25:29 by ablizniu          #+#    #+#             */
/*   Updated: 2019/06/26 17:50:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

inline void				ft_drawscreen_0(int32_t *border_b_h,
						int32_t *border_t_h, t_heigth_wall wall)
{
	*border_b_h = wall.border_b_h;
	*border_t_h = wall.border_t_h;
}

inline t_draw_save		ft_drawscreen_1(t_main *m, t_ray ray,
						t_heigth_wall *wall, t_buffer *buffer)
{
	t_draw_save			sv_draw;

	ft_bzero(&sv_draw, sizeof(t_draw_save));
	if (ray.camdist < 0.005)
		ray.camdist = 0.005;
	ft_get_wall_heigth(m, ray, wall);
	ft_get_border_bot(m, ray, wall);
	ft_get_border_top(m, ray, wall);
	ft_get_floor(m, ray, wall);
	ft_get_ceil(m, ray, wall, buffer);
	if (wall->floor_h.flag == 1 && m->sector[ray.num_sect].textures.floor != 5)
		ft_draw_floor(m, ray, *wall, buffer);
	if (m->sector[ray.num_sect].transit[ray.wall_sect] == -1)
		ft_draw_wall(m, ray, *wall, buffer);
	if (wall->border_bot.flag == 1 || wall->border_top.flag == 1)
		ft_draw_border(m, ray, *wall, buffer);
	if (wall->ceil_h.flag == 1 && m->sector[ray.num_sect].textures.celling >= 0)
		ft_draw_cell(m, ray, *wall, buffer);
	sv_draw.buffer_bot = wall->end < buffer->buffer_draw_bot ?
	wall->end : buffer->buffer_draw_bot;
	sv_draw.buffer_top = wall->start > buffer->buffer_draw_top ?
	wall->start : buffer->buffer_draw_top;
	sv_draw.old_w = ray.w;
	return (sv_draw);
}
