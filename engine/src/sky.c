/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:35:29 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:19:16 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_init_sky(t_main *m)
{
	m->sky.start.x = 0;
	m->sky.start.y = 300;
	m->sky.end.x = 500;
	m->sky.end.y = 600;
	m->sky.w = 500;
	m->sky.h = 300;
}

void			ft_draw_sky(t_main *m)
{
	t_iter		iter;
	int			color;
	double		lenx;
	double		leny;

	lenx = m->sky.w / (double)WIDTH;
	leny = m->sky.h / (double)HEIGHT;
	iter.i = 0;
	while (iter.i < WIDTH)
	{
		iter.j = 0;
		iter.x = m->sky.start.x + iter.i * lenx;
		while (iter.j < HEIGHT)
		{
			iter.y = m->sky.start.y + iter.j * leny;
			color = ft_get_pixel(m->sky.sky, iter.x, iter.y);
			ft_put_pixel(m, iter.i, iter.j, color);
			iter.j++;
		}
		iter.i++;
	}
}
