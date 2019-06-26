/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:34:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:55 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_gravity(t_main *m)
{
	float		force_jump;

	force_jump = 1.0;
	if (m->player.jump_h > 0)
		m->player.jump_h -= force_jump;
	else
		m->player.jump_h = 0;
	if (m->player.pos.z >= m->sector[m->player.sector].heigth.floor)
	{
		m->eventcall.is_ground = 0;
		if (m->player.pos.z - force_jump <
				m->sector[m->player.sector].heigth.floor)
			m->player.pos.z = m->sector[m->player.sector].heigth.floor;
		else
			m->player.pos.z -= force_jump;
		if (m->player.pos.z == m->sector[m->player.sector].heigth.floor)
			m->eventcall.is_ground = 1;
	}
}

void			ft_de_gravity(t_main *m)
{
	float		force_jump;

	force_jump = 0.4;
	if (m->player.pos.z <= m->sector[m->player.sector].heigth.floor)
	{
		m->eventcall.is_ground = 0;
		if (m->player.pos.z + force_jump >
				m->sector[m->player.sector].heigth.floor)
			m->player.pos.z = m->sector[m->player.sector].heigth.floor;
		else
			m->player.pos.z += force_jump;
		if (m->player.pos.z == m->sector[m->player.sector].heigth.floor)
			m->eventcall.is_ground = 1;
	}
}

static void		ft_transform_vec_x(t_main *m)
{
	float		ancos;
	float		ansin;

	ancos = cos(m->player.angle.hor * M_PI / 180);
	ansin = sin(m->player.angle.hor * M_PI / 180);
	if (m->eventcall.rot_left == 1)
	{
		m->sky.start.x += 15;
		m->sky.end.x += 15;
		m->player.angle.hor += 5.0;
		m->player.vec.x = VECX * ancos - VECY * ansin;
		m->player.vec.y = VECX * ansin + VECY * ancos;
		m->eventcall.rot_left = 0;
		m->eventcall.rot_rigth = 0;
	}
	else if (m->eventcall.rot_rigth == 1)
	{
		m->sky.start.x -= 15;
		m->sky.end.x -= 15;
		m->player.angle.hor -= 5.0;
		m->player.vec.x = VECX * ancos - VECY * ansin;
		m->player.vec.y = VECX * ansin + VECY * ancos;
		m->eventcall.rot_left = 0;
		m->eventcall.rot_rigth = 0;
	}
}

static void		ft_transform_vec_y(t_main *m)
{
	t_iter		iter;

	iter.ancos = cos(m->player.angle.ver * M_PI / 180);
	iter.ansin = sin(m->player.angle.ver * M_PI / 180);
	if (m->eventcall.rot_up == 1 && m->player.angle.ver <= 90)
	{
		m->sky.start.y -= 5;
		m->sky.end.y -= 10;
		m->player.angle.ver += 3;
		m->player.ecvator += 15;
		m->player.vec.z = VECX * iter.ancos - VECY * iter.ansin;
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 0;
	}
	else if (m->eventcall.rot_down == 1 && m->player.angle.ver >= -90)
	{
		m->sky.start.y += 5;
		m->sky.end.y += 5;
		m->player.angle.ver -= 3;
		m->player.ecvator -= 15;
		m->player.vec.z = VECX * iter.ancos - VECY * iter.ansin;
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 0;
	}
}

void			ft_transform(t_main *m)
{
	ft_transform_pos(m);
	ft_transform_jump(m);
	ft_transform_vec_x(m);
	ft_transform_vec_y(m);
	ft_transform_strafe(m);
	ft_geg(m);
}
