/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_transform_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:57 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:18:59 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_geg(t_main *m)
{
	if (m->eventcall.is_ground == 1)
	{
		if (m->eventcall.geg_flag == 1)
			m->player.p_he = 3.0;
		if (m->eventcall.geg_flag == 0)
			m->player.p_he = 7.0;
	}
}

void		ft_transform_jump(t_main *m)
{
	static double	force_jump = 1.5;

	if (0)
	{
		if (force_jump >= 0.1)
			force_jump -= 0.1;
		m->player.p_he += force_jump;
		m->player.jump_h += force_jump;
		if (m->player.p_he >= 14.0)
			m->eventcall.jump_event = 0;
		if (force_jump <= 0.1)
			force_jump = 1.5;
	}
}

void		ft_transform_strafe(t_main *m)
{
	float		ancos;
	float		ansin;
	t_vertex	pos_vec;

	if (m->eventcall.strafe_rigth == 1 && m->eventcall.strafe_left == 0)
	{
		ancos = cos((m->player.angle.hor + 90.0) * M_PI / 180);
		ansin = sin((m->player.angle.hor + 90.0) * M_PI / 180);
		pos_vec.x = (VECX * ancos - VECY * ansin) * m->player.movespeed;
		pos_vec.y = (VECX * ansin + VECY * ancos) * m->player.movespeed;
		ft_collision(m, pos_vec, 1.0);
	}
	else if (m->eventcall.strafe_left == 1 && m->eventcall.strafe_rigth == 0)
	{
		ancos = cos((m->player.angle.hor - 90) * M_PI / 180);
		ansin = sin((m->player.angle.hor - 90) * M_PI / 180);
		pos_vec.x = (VECX * ancos - VECY * ansin) * m->player.movespeed;
		pos_vec.y = (VECX * ansin + VECY * ancos) * m->player.movespeed;
		ft_collision(m, pos_vec, 1.0);
	}
}

void		ft_transform_pos(t_main *m)
{
	float		ancos;
	float		ansin;
	t_vertex	pos_vec;

	ancos = cos((m->player.angle.hor) * M_PI / 180);
	ansin = sin((m->player.angle.hor) * M_PI / 180);
	if (m->eventcall.move_up == 1 && m->eventcall.move_down == 0)
	{
		pos_vec.x = (VECX * ancos - VECY * ansin) * m->player.movespeed;
		pos_vec.y = (VECX * ansin + VECY * ancos) * m->player.movespeed;
		ft_collision(m, pos_vec, 1.0);
	}
	else if (m->eventcall.move_down == 1 && m->eventcall.move_up == 0)
	{
		pos_vec.x = (VECX * ancos - VECY * ansin) * m->player.movespeed;
		pos_vec.y = (VECX * ansin + VECY * ancos) * m->player.movespeed;
		ft_collision(m, pos_vec, -1.0);
	}
}
