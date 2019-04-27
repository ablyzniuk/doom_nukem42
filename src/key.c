/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:34:53 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/04/04 14:34:58 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_key_exit(t_main *m, int *run)
{
	if (m->sdl.event.type == SDL_QUIT  ||
		(SDL_SCANCODE_ESCAPE == m->sdl.event.key.keysym.scancode))
			*run = 0;
}

// обработчик клавиатуры
static void		ft_key_move(t_main *m)
{
	if (m->sdl.event.type == SDL_KEYDOWN && m->sdl.event.key.keysym.sym == SDLK_w)
		m->eventcall.move_up = 1;
	if (m->sdl.event.type == SDL_KEYDOWN && m->sdl.event.key.keysym.sym == SDLK_s)
		m->eventcall.move_down = 1;
	if (m->sdl.event.type == SDL_KEYDOWN && m->sdl.event.key.keysym.sym == SDLK_a)
		m->eventcall.strafe_left = 1;
	if (m->sdl.event.type == SDL_KEYDOWN && m->sdl.event.key.keysym.sym == SDLK_d)
		m->eventcall.strafe_rigth = 1;
	if (m->sdl.event.type == SDL_KEYDOWN && m->sdl.event.key.keysym.sym == SDLK_SPACE && m->eventcall.jump_event == 0)
		m->eventcall.jump_event = 1;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_w)
		m->eventcall.move_up = 0;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_s)
		m->eventcall.move_down = 0;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_a)
		m->eventcall.strafe_left = 0;
	if (m->sdl.event.type == SDL_KEYUP && m->sdl.event.key.keysym.sym == SDLK_d)
		m->eventcall.strafe_rigth = 0;
}

void	ft_key(t_main *m, int *run)
{
	ft_key_exit(m, run);
	ft_key_move(m);
}
