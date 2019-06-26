/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:15:47 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:23 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			gui_buttondown(t_main *main, SDL_Event event)
{
	int			i;
	int			x;
	int			y;

	i = -1;
	x = event.motion.x;
	y = event.motion.y;
	while (++i < 4)
		if (x >= main->pict.sstart[i][0] && x <= main->pict.eend[i][0]
			&& y >= main->pict.sstart[i][1] && y <= main->pict.eend[i][1])
			break ;
	if (i < 4)
		main->difficulty = i + 1;
}

static void		ft_rot_horizontal(t_main *m)
{
	if (m->sdl.event.motion.xrel > 0 && m->sdl.event.type == SDL_MOUSEMOTION)
	{
		m->eventcall.rot_left = 1;
		m->eventcall.rot_rigth = 0;
	}
	else if (m->sdl.event.motion.xrel < 0 &&
			m->sdl.event.type == SDL_MOUSEMOTION)
	{
		m->eventcall.rot_left = 0;
		m->eventcall.rot_rigth = 1;
	}
}

static void		ft_rot_vertical(t_main *m)
{
	if (m->sdl.event.motion.yrel < 0 && m->sdl.event.type == SDL_MOUSEMOTION)
	{
		m->eventcall.rot_up = 1;
		m->eventcall.rot_down = 0;
	}
	else if (m->sdl.event.motion.yrel > 0 &&
			m->sdl.event.type == SDL_MOUSEMOTION)
	{
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 1;
	}
}

void			ft_buttondown(t_main *m)
{
	if (m->sdl.event.type == SDL_MOUSEBUTTONDOWN && m->player.ammo != 0)
		m->anim.curr = 2;
}

void			ft_mouse(t_main *m)
{
	ft_buttondown(m);
	ft_rot_horizontal(m);
	ft_rot_vertical(m);
}
