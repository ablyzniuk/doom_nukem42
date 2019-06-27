/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 03:35:07 by ablizniu          #+#    #+#             */
/*   Updated: 2019/06/27 17:07:11 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static double	ft_calc_angle(double x1, double y1, double x2, double y2)
{
	double		result;

	result = (x1 * y1 + x2 * y2) / (sqrt(pow(x1, 2) + pow(x2, 2)) *
									sqrt(pow(y1, 2) + pow(y2, 2)));
	return (acos(result) * ANG / M_PI);
}

void			ft_draw_sprite(t_main *m, int32_t x, int32_t y, double cam)
{
	t_iter		iter;
	int			*col;

	iter.len = 200.0;
	iter.sv = y;
	iter.x = 0;
	iter.y = -1;
	iter.dx = m->sprite.ch->w / (iter.len - cam);
	iter.dy = m->sprite.ch->h / (iter.len - cam);
	while (++iter.y * iter.dy < m->sprite.ch->w)
	{
		iter.x = 0;
		y = iter.sv;
		while (iter.x * iter.dx < m->sprite.ch->h)
		{
			GET_COLOR(col, m->sprite.ch->pixels, (int32_t)(iter.x * iter.dx),
					m->sprite.ch->pitch, (int32_t)(iter.y * iter.dy),
					m->sprite.ch->format->BytesPerPixel);
			if (*col > 0x000000)
				ft_put_pixel(m, x, y, *col);
			iter.x++;
			y++;
		}
		x++;
	}
}

void			ft_sprite(t_main *m)
{
	t_iter		iter;
	double		angle;
	t_vertex	pos;

	iter.w = 0;
	iter.y = HALFHEIGTH;
	iter.x = 200;
	angle = ft_calc_angle(pos.x - m->player.pos.x, pos.y - m->player.pos.y,
			m->spr_data.pos.x - m->player.pos.x,
			m->spr_data.pos.y - m->player.pos.y);
	m->spr_data.anglee = angle;
	pos.x = 1;
	pos.y = 1;
	if (angle < 33.0 && m->eventcall.eee == 0)
	{
		while (iter.w < WIDTH)
		{
			if (floor(angle) == floor(m->spr_data.angle[iter.w]))
			{
				ft_draw_sprite(m, iter.w, iter.y, m->spr_data.dist[iter.w]);
				break ;
			}
			iter.w++;
		}
	}
}
