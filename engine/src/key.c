/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:34:53 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:02 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_key_move_4(t_main *m)
{
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_w)
		m->eventcall.move_up = 0;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_s)
		m->eventcall.move_down = 0;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_a)
		m->eventcall.strafe_left = 0;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_d)
		m->eventcall.strafe_rigth = 0;
	if (m->sdl.event.type == SDL_KEYUP &&
			m->sdl.event.key.keysym.sym == SDLK_LCTRL)
		m->eventcall.geg_flag = 0;
}

static void		ft_key_move_3(t_main *m)
{
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_r)
		m->anim.curr = 3;
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_LSHIFT)
		m->zhora_run = 5.0;
	if (m->sdl.event.type == SDL_KEYUP &&
			m->sdl.event.key.keysym.sym == SDLK_LSHIFT)
		m->zhora_run = 0;
}

static void		ft_key_move_2(t_main *m)
{
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		if (m->eventcall.flag_debug == 1)
			m->eventcall.flag_debug = 0;
		else
			m->eventcall.flag_debug = 1;
	}
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_KP_PLUS)
	{
		m->player.pos.z++;
		m->sector[m->player.sector].heigth.cell++;
		m->sector[m->player.sector].heigth.floor++;
	}
	if (m->sdl.event.type == SDL_KEYUP &&
			m->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
	{
		m->player.pos.z--;
		m->sector[m->player.sector].heigth.cell--;
		m->sector[m->player.sector].heigth.floor--;
	}
}

static void		ft_key_move_1(t_main *m)
{
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_w)
		m->eventcall.move_up = 1;
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_s)
		m->eventcall.move_down = 1;
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_a)
		m->eventcall.strafe_left = 1;
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_d)
		m->eventcall.strafe_rigth = 1;
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_SPACE &&
			m->eventcall.look_jump == 1)
		m->eventcall.jump_event = 1;
	if (m->sdl.event.type == SDL_KEYDOWN &&
			m->sdl.event.key.keysym.sym == SDLK_LCTRL &&
			m->eventcall.jump_event == 0)
		m->eventcall.geg_flag = 1;
	if (m->sdl.event.type == SDL_KEYUP &&
			m->sdl.event.key.keysym.sym == SDLK_LCTRL)
		m->eventcall.geg_flag = 0;
}

void			ft_key(t_main *m, int *run)
{
	ft_key_exit(m, run);
	ft_key_move_1(m);
	ft_key_move_2(m);
	ft_key_move_3(m);
	ft_key_move_4(m);
}
