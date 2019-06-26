/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 03:23:51 by ablizniu          #+#    #+#             */
/*   Updated: 2019/06/23 15:19:20 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			draw_bmp(t_main *m, SDL_Surface *bmp, int win_y, int win_x)
{
	int			x;
	int			y;
	int			*color;

	y = -1;
	while (++y < bmp->h)
	{
		x = -1;
		while (++x < bmp->w)
		{
			color = bmp->pixels + y * bmp->pitch +
					x * bmp->format->BytesPerPixel;
			if (*color != ~0xFF0F00 && *color != 0x000000)
				ft_put_pixel(m, win_x + x, win_y + y, *color);
		}
	}
}

void			draw_menu(t_main *main)
{
	int			i;

	i = -1;
	while (++i < 4)
		draw_bmp(main, main->pict.butt[i],
				main->pict.sstart[i][1], main->pict.sstart[i][0]);
}

void			init_pos(t_main *main)
{
	int			i;
	int			y_start;
	int			x_start;
	int			y_move;

	i = -1;
	main->difficulty = -1;
	y_start = HALFHEIGTH - (main->pict.butt[0]->h * 2) - PADD * 2;
	x_start = HALFWIDTH - main->pict.butt[0]->w / 2;
	y_move = main->pict.butt[0]->h + PADD;
	while (++i < 4)
	{
		main->pict.sstart[i][0] = x_start;
		main->pict.sstart[i][1] = y_start;
		main->pict.eend[i][0] = x_start + main->pict.butt[0]->w;
		main->pict.eend[i][1] = y_start + main->pict.butt[0]->h;
		y_start += main->pict.butt[0]->h + PADD;
	}
}

void			init_buttons(t_main *main)
{
	int			i;

	i = -1;
	main->pict.butt[0] = SDL_LoadBMP("../resources/en/butt/easy.bmp");
	main->pict.butt[1] = SDL_LoadBMP("../resources/en/butt/med.bmp");
	main->pict.butt[2] = SDL_LoadBMP("../resources/en/butt/hard.bmp");
	main->pict.butt[3] = SDL_LoadBMP("../resources/en/butt/death.bmp");
	while (++i < 4)
		if (main->pict.butt[i] == NULL)
			print_error("Missing button texture");
	init_pos(main);
}

void			start_menu(t_main *main)
{
	t_sdl		sdl;
	int			running;

	sdl = main->sdl;
	running = 1;
	while (running)
	{
		draw_bmp(main, main->pict.start, 0, 0);
		draw_menu(main);
		while (SDL_PollEvent(&(sdl.event)))
		{
			if (sdl.event.type == SDL_QUIT ||
					(sdl.event.type == SDL_KEYDOWN &&
					sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				running = 0;
			if (sdl.event.type == SDL_MOUSEBUTTONDOWN)
				gui_buttondown(main, sdl.event);
			if (main->difficulty != -1)
				running = 0;
			SDL_UpdateWindowSurface(main->sdl.window);
		}
	}
}
