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


//   jump фиксить потом
static void		ft_transform_jump(t_main *m)
{
	static float	jump = 0.0;
	static int		flag = 0;

	if (m->eventcall.jump_event == 1)
	{
		if (flag == 0.0)
		{
			if (jump < 9.0)
				m->player.pos.z += jump;
			if (m->player.pos.z < 9.0)
			{
				flag = 1;
				jump = 0.0;
			}
			jump += 0.3;
		}
		if (flag == 1)
		{
			if (jump < 9.0)
				m->player.pos.z -= jump;
			if (m->player.pos.z < 9.0)
			{
				m->eventcall.jump_event = 0;
				jump = 0.0;
				flag = 0;
				return ;								
			}
			jump += 0.3;
		}
	}
}

// стрейф
static void		ft_transform_strafe(t_main *m)
{
	float		ancos;
	float		ansin;
	int			res;
	t_vertex	ray;

	if (m->eventcall.strafe_rigth == 1)
	{
		ancos = cos((m->player.angle.hor + 90) * M_PI / 180);
		ansin = sin((m->player.angle.hor + 90) * M_PI / 180);
		ray.x = m->player.pos.x + (VECX * ancos - VECY * ansin) * m->player.movespeed;
		ray.y = m->player.pos.y + (VECX * ansin + VECY * ancos) * m->player.movespeed;
		res = ft_collision(m, m->player.pos, ray);
		if (res != -1)
		{
			m->player.pos.x = ray.x;
			m->player.pos.y = ray.y;
		}
	}
	else if (m->eventcall.strafe_left == 1)
	{
		ancos = cos((m->player.angle.hor - 90) * M_PI / 180);
		ansin = sin((m->player.angle.hor - 90) * M_PI / 180);
		ray.x = m->player.pos.x + (VECX * ancos - VECY * ansin) * m->player.movespeed;
		ray.y = m->player.pos.y + (VECX * ansin + VECY * ancos) * m->player.movespeed;
		res = ft_collision(m, m->player.pos, ray);
		if (res != -1)
		{
			m->player.pos.x = ray.x;
			m->player.pos.y = ray.y;
		}
	}
}

//движение
static void		ft_transform_pos(t_main *m)
{
	float		ancos;
	float		ansin;
	int			res;
	t_vertex	ray;

	if (m->eventcall.move_up == 1)
	{
		ancos = cos((m->player.angle.hor) * M_PI / 180);
		ansin = sin((m->player.angle.hor) * M_PI / 180);
		ray.x = m->player.pos.x + (VECX * ancos - VECY * ansin) * m->player.movespeed;
		ray.y = m->player.pos.y + (VECX * ansin + VECY * ancos) * m->player.movespeed;
		res = ft_collision(m, m->player.pos, ray);
		if (res != -1)
		{
			m->player.pos.x = ray.x;
			m->player.pos.y = ray.y;
		}
	}
	else if (m->eventcall.move_down == 1)
	{
		ancos = cos((m->player.angle.hor) * M_PI / 180);
		ansin = sin((m->player.angle.hor) * M_PI / 180);
		ray.x = m->player.pos.x - (VECX * ancos - VECY * ansin) * m->player.movespeed;
		ray.y = m->player.pos.y - (VECX * ansin + VECY * ancos) * m->player.movespeed;
		res = ft_collision(m, m->player.pos, ray);
		if (res != -1)
		{
			m->player.pos.x = ray.x;
			m->player.pos.y = ray.y;
		}
	}
}

// повороты
static void		ft_transform_vec_x(t_main *m)
{
	float	ancos;
	float	ansin;

	ancos = cos(m->player.angle.hor * M_PI / 180);
	ansin = sin(m->player.angle.hor * M_PI / 180);
	if (m->eventcall.rot_left == 1)
	{
		m->player.angle.hor += 2;
		m->player.vec.x = VECX * ancos - VECY * ansin;
		m->player.vec.y = VECX * ansin + VECY * ancos;
		m->eventcall.rot_left = 0;
		m->eventcall.rot_rigth = 0;
	}
	else if (m->eventcall.rot_rigth == 1)
	{
		m->player.angle.hor -= 2;
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
	if (m->eventcall.rot_up == 1)
	{
		m->player.angle.ver += 1;
		m->player.ecvator += 15;
		m->player.vec.z = VECX * ancos - VECY * ansin;
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 0;
	}
	else if (m->eventcall.rot_down == 1)
	{
		m->player.angle.ver -= 1;
		m->player.ecvator -= 15;
		m->player.vec.z = VECX * ancos - VECY * ansin;
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 0;
	}
}

void			ft_transform(t_main	*m)
{
	ft_transform_vec_x(m);
	ft_transform_vec_y(m);
	ft_transform_pos(m);
	ft_transform_strafe(m);
	ft_transform_jump(m);
}
