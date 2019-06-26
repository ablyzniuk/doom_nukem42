/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:22 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:37 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				init_edit(t_edit **edit)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	(*edit)->zoom = WIN_W / 100;
	(*edit)->sett = vertex;
	(*edit)->sdl = (t_sdl *)ft_memalloc(sizeof(t_sdl));
	(*edit)->sdl->win = SDL_CreateWindow(
			"Doom Nukem Map Editor",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WIN_W,
			WIN_H,
			SDL_WINDOW_ALLOW_HIGHDPI);
	(*edit)->sdl->surface = SDL_GetWindowSurface((*edit)->sdl->win);
	(*edit)->update = 1;
	(*edit)->player.current_sect = -1;
	(*edit)->index = -1;
	SDL_SetWindowIcon((*edit)->sdl->win, (*edit)->icon);
	clear_binder(edit);
}

int					main(void)
{
	t_edit			*edit;
	int				mode;
	int				fd;

	edit = (t_edit *)ft_memalloc(sizeof(t_edit));
	init_edit(&edit);
	load_img_pass(edit);
	load_img_active(edit);
	load_img_obj(edit);
	set_poss(&edit);
	load_text(edit);
	update(&edit);
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open("../resources/map.txt", O_WRONLY | O_CREAT | O_TRUNC, mode);
	write_map(edit, fd);
	terminate("doomMapEditor closed successfully", edit->sdl);
	return (0);
}

void				terminate(char *str, t_sdl *sdl)
{
	ft_putendl(str);
	if (sdl != NULL)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
	exit(0);
}
