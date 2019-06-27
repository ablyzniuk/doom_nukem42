/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lava_and_health_bar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:23:13 by ablizniu          #+#    #+#             */
/*   Updated: 2019/06/27 12:48:13 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			draw_scaled_bmp(t_main *main,
				SDL_Surface *bmp, int win_y, int win_x)
{
	double		diff_x;
	double		diff_y;
	int32_t		x;
	int32_t		y;
	int32_t		*color;

	y = 0;
	diff_x = (double)WIDTH / bmp->w;
	diff_y = (double)HEIGHT / bmp->h;
	while (y < bmp->h)
	{
		x = 0;
		while (x < bmp->w)
		{
			color = bmp->pixels + y * bmp->pitch +
					x * bmp->format->BytesPerPixel;
			if (*color != ~0xFF0F00 && *color != 0x000000)
				ft_put_pixel(main, win_x + (int32_t)(x * diff_x),
						win_y + (int32_t)(y * diff_y), *color);
			x++;
		}
		y++;
	}
}

static clock_t	calc_time_delay(t_main *main)
{
	clock_t		time;

	time = (main->time + CLOCKS_PER_SEC / 500);
	return (time);
}

void			decreaze_hp(t_main *main)
{
	if (main->sector[main->player.sector].textures.floor == 6)
	{
		if (clock() >= calc_time_delay(main))
		{
			if ((int)main->player.p_he <= 7)
				main->player.hp -= 5;
			main->time = clock();
		}
	}
}

void			final_scene(t_main *main)
{
	if (main->player.hp <= 0)
	{
		draw_bmp(main, main->pict.end[1], 0, 0);
		draw_bmp(main, main->pict.end[0], 0, 0);
		while (!(main->sdl.event.type == SDL_QUIT ||
		(SDL_SCANCODE_ESCAPE == main->sdl.event.key.keysym.scancode)))
		{
			draw_bmp(main, main->pict.end[1], 0, 0);
			draw_scaled_bmp(main, main->pict.end[0], 0, 0);
			SDL_UpdateWindowSurface(main->sdl.window);
			SDL_PollEvent(&main->sdl.event);
		}
		exit(0);
	}
}
