/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:36 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:41 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				keydown(t_edit **edit, SDL_Event event)
{
	if ((*edit)->sett == textures && (*edit)->ass_tex != NULL)
	{
		if (event.key.keysym.sym == SDLK_1)
			(*edit)->index = 0;
		else if (event.key.keysym.sym == SDLK_2)
			(*edit)->index = 1;
		else if (event.key.keysym.sym == SDLK_3)
			(*edit)->index = 2;
	}
	if ((*edit)->ass_tex && ((*edit)->sett == cceil || (*edit)->sett == ffloor))
	{
		if ((*edit)->sett == cceil && event.key.keysym.sym == SDLK_KP_PLUS)
			(*edit)->ass_tex->hceil += 1;
		else if ((*edit)->sett == cceil &&
			event.key.keysym.sym == SDLK_KP_MINUS)
			(*edit)->ass_tex->hceil -= 1;
		if ((*edit)->sett == ffloor &&
			event.key.keysym.sym == SDLK_KP_PLUS)
			(*edit)->ass_tex->hfloor += 1;
		else if ((*edit)->sett == ffloor &&
			event.key.keysym.sym == SDLK_KP_MINUS)
			(*edit)->ass_tex->hfloor -= 1;
	}
}

void				gui_buttondown(t_edit **edit, SDL_Event event)
{
	int				i;
	int				x;
	int				y;

	i = -1;
	x = event.motion.x;
	y = event.motion.y;
	while (++i < NUM_TEX_P)
		if (x >= (*edit)->pos_start[i][0] && x <= (*edit)->pos_end[i][0]
			&& y >= (*edit)->pos_start[i][1] && y <= (*edit)->pos_end[i][1])
			break ;
	if (i < NUM_TEX_T)
		(*edit)->sett = i;
	else if ((*edit)->sett == textures &&
			(*edit)->ass_tex != NULL && (*edit)->index != -1)
	{
		(*edit)->ass_tex->texture[(*edit)->index] = i - NUM_TEX_T;
		(*edit)->sett = vertex;
		(*edit)->ass_tex = NULL;
		(*edit)->index = -1;
	}
}

void				mousebuttondown(t_edit **edit, SDL_Event event)
{
	if (event.motion.x > (*edit)->x_bounds && (*edit)->sect_is_closed == 1)
		gui_buttondown(edit, event);
	else
	{
		if ((*edit)->sett == cceil || (*edit)->sett == ffloor)
			edit_ceil_floor(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == vertex && event.motion.x < (*edit)->x_bounds)
			sect_record(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == portal)
			declare_portal(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == bind)
			bind_portals(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == editer)
			edit_vertex(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == player)
			set_player(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == bad_big)
			set_enemy(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == object)
			set_obj(edit, event.motion.x, event.motion.y);
		else if ((*edit)->sett == textures)
			pick_texture(edit, event.motion.x, event.motion.y);
	}
}

void				render_everything(t_edit *edit)
{
	set_grid(edit);
	data_render(edit);
	if (edit->portal_start != NULL)
		pixel_put(edit->sdl, edit->portal_start->x,
		edit->portal_start->y, 0x00FF00);
	if (edit->portal_end != NULL)
		pixel_put(edit->sdl, edit->portal_end->x,
		edit->portal_end->y, 0x00FF00);
	background_render(edit);
	icons_render(edit, edit->bmp, edit->sdl);
	if (edit->sett == textures && edit->ass_tex == NULL)
		draw_bmp(edit->sdl, edit->text[0],
				WIN_H - SETT_PAD * 2 - edit->text[0]->h, SETT_PAD);
	else if (edit->sett == textures && edit->index == -1)
		draw_bmp(edit->sdl, edit->text[1],
				WIN_H - SETT_PAD * 2 - edit->text[1]->h, SETT_PAD);
}

void				update(t_edit **p_edit)
{
	t_edit			*edit;
	t_sdl			*sdl;

	edit = *p_edit;
	sdl = edit->sdl;
	while (edit->update)
	{
		SDL_FillRect(sdl->surface, NULL, 0x000000);
		while (SDL_PollEvent(&(sdl->event)))
		{
			if (sdl->event.type == SDL_QUIT ||
				(sdl->event.type == SDL_KEYDOWN &&
				sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				edit->update = 0;
			if (sdl->event.type == SDL_KEYDOWN)
				keydown(&edit, sdl->event);
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				mousebuttondown(&edit, sdl->event);
		}
		render_everything(edit);
		SDL_UpdateWindowSurface(sdl->win);
	}
}
