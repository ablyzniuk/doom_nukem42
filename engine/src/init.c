/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:38:35 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/26 18:33:09 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_main			*init_main(void)
{
	t_main		*main;

	if (!(main = (t_main *)ft_memalloc(sizeof(t_main))))
		print_error(BAD_ALLOC);
	return (main);
}

void			ft_init_setting(t_main *m)
{
	m->setting.fog = 0;
}

void			ft_init_event_var(t_main *m)
{
	m->eventcall.move_down = 0;
	m->eventcall.is_ground = 1;
	m->eventcall.move_up = 0;
	m->eventcall.rot_down = 0;
	m->eventcall.rot_left = 0;
	m->eventcall.rot_rigth = 0;
	m->eventcall.rot_up = 0;
	m->eventcall.strafe_left = 0;
	m->eventcall.strafe_rigth = 0;
	m->eventcall.jump_event = 0;
	m->eventcall.look_jump = 1;
}

void			ft_init(t_main *m, char *way)
{
	ft_init_sky(m);
	read_file(m, way);
	ft_cr_cols_init(m);
	ft_init_event_var(m);
	ft_init_setting(m);
	m->time = 0;
	m->music.switcher = false;
	m->eventcall.look_jump = 1;
	m->player.angle.hor = 0.0;
	m->player.angle.ver = 0.0;
	m->player.jump_h = 0;
	m->player.vec.x = 1;
	m->player.vec.y = 0;
	m->player.vec.z = 0;
	m->player.hp = 100;
	m->player.movespeed = 0;
	m->player.rotspeed = 0;
	m->player.p_he = 7;
	m->player.ecvator = HEIGHT / 2;
	m->player.ammo = 10;
	m->player.hp = 100;
}
