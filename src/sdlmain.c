/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdlmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:23:29 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 13:23:30 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

// сдл инит
void    ft_sdlinit(t_main *m)
{
	TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
	m->sdl.window = SDL_CreateWindow(
		"Doom Nukem",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_ALLOW_HIGHDPI);
	m->sdl.winsurface = SDL_GetWindowSurface(m->sdl.window);
	SDL_SetRelativeMouseMode(1);
	ft_load_texture(m);
}

//игровой цыкл
void    ft_sdlloop(t_main *m)
{
	int	run;

	run = 1;
	while (run)
	{
		SDL_FillRect(m->sdl.winsurface, NULL, 0x000000);
		ft_gravity(m);
		ft_draw_sky(m);
		ft_draw_map(m);
		ft_transform(m);
		while (SDL_PollEvent(&m->sdl.event))
		{
			ft_key(m, &run);
			ft_mouse(m);
		}
		ft_debug(m);
		SDL_UpdateWindowSurface(m->sdl.window);
	//	ft_fps_look(m);
		ft_fps_utils(m);
	}
}