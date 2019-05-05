/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:35:29 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 14:35:30 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_init_sky(t_main *m)
{
	m->sky.start.x = 0;
	m->sky.start.y = 300;
	m->sky.end.x = 500;
	m->sky.end.y = 600;
	m->sky.w = 500;
	m->sky.h = 300;
}

void    ft_draw_sky(t_main *m)
{
	int x;
	int y;
	int	i;
	int	j;
	int	color;
	double	lenx;
	double	leny;

	lenx = m->sky.w / (double)WIDTH;
	leny = m->sky.h / (double)HEIGHT;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		x = m->sky.start.x + i * lenx;
		while (j < HEIGHT)
		{
			
			y = m->sky.start.y + j * leny;
			color = ft_get_pixel(m->sky.sky, x, y);
		//	printf("|%d %d\n|", x, y);
			ft_put_pixel(m, i, j, color);
			j++;
		}
		i++;
	}
		printf("|%d %d\n|", x, y);
}