/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:49:20 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/18 19:49:21 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static	double	ft_calc_angle(double x1, double y1, double x2, double y2)
{
	double	result;

	result = (x1 * y1 + x2 * y2) / (sqrt(pow(x1, 2) + pow(x2, 2)) *
	sqrt(pow(y1, 2) + pow(y2, 2)));
	
	//printf("%f %f %f \n", result, x2, y2);
	return (acos(result) * ANG / M_PI);
}

void	ft_draw_sprite(t_main *m, int32_t x, int32_t y)
{
	int32_t		w = 500;
	double		len = 200.0;
	double		camdidst = 100.0;

	double		diff_x, diff_y;
	int32_t		x_ch;
	int32_t		y_ch;
	int32_t		sv;
	int			*col;


	sv = y;

	x_ch = 0;
	y_ch = 0;
	x_ch = 0;
	y_ch = 0;

	diff_x = m->sprite.ch->w / (len - camdidst);
	diff_y = m->sprite.ch->h / (len - camdidst);

	while (y_ch * diff_y < m->sprite.ch->w)
	{
		x_ch = 0;
		y = sv;
		while (x_ch * diff_x < m->sprite.ch->h)
		{
			GET_COLOR(col, m->sprite.ch->pixels, (int32_t)(x_ch * diff_x), m->sprite.ch->pitch, (int32_t)(y_ch * diff_y), m->sprite.ch->format->BytesPerPixel);
			if (*col != 0x808080 && *col > 0x000000)
				ft_put_pixel(m, x, y, *col);
			x_ch++;
			y++;
		}
		x++;
		y_ch++;
	}
	
}

void	ft_sprite(t_main *m)
{
	int32_t	x;
	int32_t	y;
	double	angle;
	t_vertex	pos;

	pos.x =	1.0;
	pos.y = 1.0;
	int w = 0;
	y = HALFHEIGTH;
	x = 200;	
	angle = ft_calc_angle(pos.x - m->player.pos.x, pos.y  - m->player.pos.y, m->spr_data.pos.x - m->player.pos.x, m->spr_data.pos.y  - m->player.pos.y);
	printf("%f %f\n", m->spr_data.vecx, m->spr_data.vecy);
	if (angle < 33.0)
	{
		while (w < WIDTH)
		{
		//	printf("%f \n", (m->spr_data.angle[w]));
			if (floor(angle) == floor(m->spr_data.angle[w]))
			{
				ft_draw_sprite(m, w, y);
				break ;
			}
			w++;
		}
	}
	
	
}

