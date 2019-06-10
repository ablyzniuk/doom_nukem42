/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:15:47 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 14:15:48 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_rot_horizontal(t_main *m)
{
	if (m->sdl.event.motion.xrel > 0 && m->sdl.event.type == SDL_MOUSEMOTION)
	{
		m->eventcall.rot_left = 1;
		m->eventcall.rot_rigth = 0;
	}
	else if (m->sdl.event.motion.xrel < 0 && m->sdl.event.type == SDL_MOUSEMOTION)
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
	else if (m->sdl.event.motion.yrel > 0 && m->sdl.event.type == SDL_MOUSEMOTION)
	{
		m->eventcall.rot_up = 0;
		m->eventcall.rot_down = 1;
	}
}

void    ft_mouse(t_main *m)
{
	ft_rot_horizontal(m);
	ft_rot_vertical(m);
}