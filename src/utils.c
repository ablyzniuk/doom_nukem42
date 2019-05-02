/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:35:24 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/04/04 14:35:27 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


// просчет пересечения двух отрезков
// лютая ebola
t_vertex	ft_intersection(t_vertex st1, t_vertex end1, t_vertex st2, t_vertex end2)
{
	t_intersection	var;
	t_vertex		point;

	var.dir1.x = end1.x - st1.x;
	var.dir1.y = end1.y - st1.y;
	var.dir2.x = end2.x - st2.x;
	var.dir2.y = end2.y - st2.y;
	var.a1 = -var.dir1.y;
	var.b1 = +var.dir1.x;
	var.d1 = -(var.a1 * st1.x + var.b1 * st1.y);
	var.a2 = -var.dir2.y;
	var.b2 = +var.dir2.x;
	var.d2 = -(var.a2 * st2.x + var.b2 * st2.y);
	var.seg_line2_s = var.a2 * st1.x + var.b2 * st1.y + var.d2;
	var.seg_line2_e = var.a2 * end1.x + var.b2 * end1.y + var.d2;
	var.seg_line1_s = var.a1 * st2.x + var.b1 * st2.y + var.d1;
	var.seg_line1_e = var.a1 * end2.x + var.b1 * end2.y + var.d1;
	point.x = -1;
	point.y = -1;
	point.z = -1;
	if (var.seg_line2_s * var.seg_line2_e >= 0 || var.seg_line1_s * var.seg_line1_e >= 0)
		return (point);
	var.u = (double)var.seg_line2_s / (double)(var.seg_line2_s - var.seg_line2_e);
	// кординаты пересечения
	point.x = st1.x + var.u * var.dir1.x;
	point.y = st1.y + var.u * var.dir1.y;
	// как далеко
	point.z = var.u;
	return (point);
}

//фпс лок
void	ft_fps_look(t_main *m)
{
	float	frame;

	m->fps.lookoldtime = m->fps.looktime;
	m->fps.looktime = SDL_GetTicks();
	frame = m->fps.looktime - m->fps.lookoldtime;
	if (frame < TICKS_FRAME)
		SDL_Delay(TICKS_FRAME - frame);
	m->fps.looktime = SDL_GetTicks();
}

// ebola ??
void	ft_fps_utils(t_main *m)
{
	m->fps.oldtime = m->fps.time;
	m->fps.time = SDL_GetTicks();
	m->fps.frametime = (m->fps.time - m->fps.oldtime) / 333.0;
	m->player.movespeed = m->fps.frametime * 0.9;
	m->player.rotspeed = m->fps.frametime * 3.0;
	//SDL_Log("%d\n", (int) (1 / m->player.rotspeed));
}