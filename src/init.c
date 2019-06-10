/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:38:35 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/06 17:38:58 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
//пускай в ините находятся все файлы для аллокации глобальных структур


t_main *init_main(void)
{
	t_main *main;

	if (!(main = ft_memalloc(sizeof(t_main))))
		print_error(BAD_ALLOC);
	return (main);
}

// ebola
void	ft_init(t_main *m)
{
	ft_init_sky(m);
	read_file(m);
	ft_cr_cols_init(m);
	// углы поворота игрока
	m->player.angle.hor = 0.0;
	m->player.angle.ver = 0.0;
	m->player.jump_h = 0;
	m->eventcall.look_jump = 1;
//	// вектора поворота игрока
	m->player.vec.x = 1;
	m->player.vec.y = 0;
	m->player.vec.z = 0;
//	// позиция игрока
//	m->player.pos.x = 1.2;
//	m->player.pos.y = 5;
//	m->player.pos.z = 0;
//	// скоость
	m->player.movespeed = 0;
	m->player.rotspeed = 0;
	m->player.p_he = 7;
//	m->player.sector = 0;
//	// обработкичи кнопок
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
	m->player.ecvator = HEIGHT / 2;
}
