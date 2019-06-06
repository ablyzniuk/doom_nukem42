/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:05:24 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/28 13:05:25 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    ft_debug(t_main *m)
{
	char	*str;

	if (m->eventcall.flag_debug == 1)
	{
		SDL_Color color_fg;
		SDL_Rect	rect;

		rect.h = 2000;
		rect.w = 2000;
		rect.x = 0;
		rect.y = 20;

		color_fg.r = 255;
		color_fg.b = 0;
		color_fg.g = 0;
		color_fg.a = 255;

		str = ft_strjoin("x | y | z | p_he: ", ft_itoa(m->player.pos.x));
		str = ft_strjoin(str, "  ");
		str = ft_strjoin(str, ft_itoa(m->player.pos.y));
		str = ft_strjoin(str, "  ");
		str = ft_strjoin(str, ft_itoa(m->player.pos.z));
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, ft_itoa(m->player.p_he));
		m->sdl.debug = TTF_RenderText_Solid(m->sdl.font, str, color_fg);
		SDL_BlitSurface(m->sdl.debug, NULL, m->sdl.winsurface, &rect);
		str = ft_strjoin("sector:  ", ft_itoa(m->player.sector));
		str = ft_strjoin(str, " fl cl:  ");
		str = ft_strjoin(str, ft_itoa(m->sector[m->player.sector].heigth.floor));
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, ft_itoa(m->sector[m->player.sector].heigth.cell));
		m->sdl.debug = TTF_RenderText_Solid(m->sdl.font, str, color_fg);
		rect.y = 40;
		SDL_BlitSurface(m->sdl.debug, NULL, m->sdl.winsurface, &rect);
		str = ft_strjoin("st:  ", ft_itoa(m->debug.top_start));
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, ft_itoa(m->debug.top_end));
		rect.y = 60;
		m->sdl.debug = TTF_RenderText_Solid(m->sdl.font, str, color_fg);
		SDL_BlitSurface(m->sdl.debug, NULL, m->sdl.winsurface, &rect);
		str = ft_strjoin("wall_sec:  ", ft_itoa(m->debug.wall));
		str = ft_strjoin(str, " ");
		rect.y = 80;
		m->sdl.debug = TTF_RenderText_Solid(m->sdl.font, str, color_fg);
		SDL_BlitSurface(m->sdl.debug, NULL, m->sdl.winsurface, &rect);
	}
}