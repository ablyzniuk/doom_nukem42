/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:34:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/04/04 14:34:32 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_gravity(t_main *m)
{
	float	force_jump;

	force_jump = 0.4;
	if (m->player.pos.z >= m->sector[m->player.sector].heigth.floor)
	{
		m->eventcall.look_jump = 0;
		m->eventcall.is_ground = 0;
		if (m->player.pos.z - force_jump < m->sector[m->player.sector].heigth.floor)
			m->player.pos.z = m->sector[m->player.sector].heigth.floor;
		else
			m->player.pos.z -= force_jump;
		if (m->player.pos.z == m->sector[m->player.sector].heigth.floor)
		{
			m->eventcall.is_ground = 1;
			m->eventcall.look_jump = 1;
		}
	}
}

void	ft_de_gravity(t_main *m)
{
	float	force_jump;

	force_jump = 0.4;
	if (m->player.pos.z <= m->sector[m->player.sector].heigth.floor)
	{
		m->eventcall.look_jump = 0;
		m->eventcall.is_ground = 0;
		if (m->player.pos.z + force_jump > m->sector[m->player.sector].heigth.floor)
			m->player.pos.z = m->sector[m->player.sector].heigth.floor;
		else
			m->player.pos.z += force_jump;
		if (m->player.pos.z == m->sector[m->player.sector].heigth.floor)
		{
			m->eventcall.is_ground = 1;
			m->eventcall.look_jump = 1;
		}
	}
}

static void		ft_geg(t_main *m)
{
	if (m->eventcall.geg_flag == 1)
		m->player.p_he = 2;
	if (m->eventcall.geg_flag == 0)
		m->player.p_he = 10;	
}

static void		ft_transform_jump(t_main *m)
{
	static	double	force_jump = 1.5;

	if (m->eventcall.jump_event == 1)
	{
		if (force_jump >= 0.1)
			force_jump -= 0.1;
		m->player.pos.z += force_jump;
		if (force_jump <= 0.1)
		{
			force_jump = 1.5;
			m->eventcall.jump_event = 0;
		}
	}
}

static void		ft_transform_strafe(t_main *m)
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

static void		ft_transform_pos(t_main *m)
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

static void		ft_transform_vec_x(t_main *m)
{
	float	ancos;
	float	ansin;

	ancos = cos(m->player.angle.hor * M_PI / 180);
	ansin = sin(m->player.angle.hor * M_PI / 180);
	if (m->eventcall.rot_left == 1)
	{
		m->sky.start.x += 15;
		m->sky.end.x += 15;
		m->player.angle.hor += 3.0;
		m->player.vec.x = VECX * ancos - VECY * ansin;
		m->player.vec.y = VECX * ansin + VECY * ancos;
		m->eventcall.rot_left = 0;
		m->eventcall.rot_rigth = 0;
	}
	else if (m->eventcall.rot_rigth == 1)
	{
		m->sky.start.x -= 15;
		m->sky.end.x -= 15;
		m->player.angle.hor -= 3.0;
		m->player.vec.x = VECX * ancos - VECY * ansin;
		m->player.vec.y = VECX * ansin + VECY * ancos;
		m->eventcall.rot_left = 0;
		m->eventcall.rot_rigth = 0;
	}
}

// вверх вниз
static void		ft_transform_vec_y(t_main *m)
{
	float	ancos;
	float	ansin;

	ancos = cos(m->player.angle.ver * M_PI / 180);
	ansin = sin(m->player.angle.ver * M_PI / 180);
	if (m->eventcall.rot_up == 1 && m->player.angle.ver <= 90)
	{
		m->sky.start.y -= 5;
		m->sky.end.y -= 10;
		m->player.angle.ver += 3;
		m->player.ecvator += 15;
		m->player.vec.z = VECX * ancos - VECY * ansin;
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 0;
	}
	else if (m->eventcall.rot_down == 1  && m->player.angle.ver >= -90)
	{
		m->sky.start.y += 5;
		m->sky.end.y += 5;
		m->player.angle.ver -= 3;
		m->player.ecvator -= 15;
		m->player.vec.z = VECX * ancos - VECY * ansin;
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 0;
	}
}

void			ft_transform(t_main	*m)
{
	ft_transform_pos(m);
	ft_transform_jump(m);
	ft_transform_vec_x(m);
	ft_transform_vec_y(m);
	ft_transform_strafe(m);
	ft_geg(m);
}
