/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resourse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:13:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:19:07 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_load_reload_1(t_main *m, int i)
{
	m->anim.r[0] = SDL_LoadBMP("../resources/en/hud/r/34.bmp");
	m->anim.r[1] = SDL_LoadBMP("../resources/en/hud/r/04.bmp");
	m->anim.r[2] = SDL_LoadBMP("../resources/en/hud/r/03.bmp");
	m->anim.r[3] = SDL_LoadBMP("../resources/en/hud/r/02.bmp");
	m->anim.r[4] = SDL_LoadBMP("../resources/en/hud/r/01.bmp");
	m->anim.r[5] = SDL_LoadBMP("../resources/en/hud/r/00.bmp");
	m->anim.r[6] = SDL_LoadBMP("../resources/en/hud/r/0.bmp");
	m->anim.r[7] = SDL_LoadBMP("../resources/en/hud/r/1.bmp");
	m->anim.r[8] = SDL_LoadBMP("../resources/en/hud/r/2.bmp");
	m->anim.r[9] = SDL_LoadBMP("../resources/en/hud/r/3.bmp");
	m->anim.r[10] = SDL_LoadBMP("../resources/en/hud/r/4.bmp");
	m->anim.r[11] = SDL_LoadBMP("../resources/en/hud/r/5.bmp");
	m->anim.r[12] = SDL_LoadBMP("../resources/en/hud/r/6.bmp");
	m->anim.r[13] = SDL_LoadBMP("../resources/en/hud/r/7.bmp");
	m->anim.r[14] = SDL_LoadBMP("../resources/en/hud/r/8.bmp");
	m->anim.r[15] = SDL_LoadBMP("../resources/en/hud/r/9.bmp");
	m->anim.r[16] = SDL_LoadBMP("../resources/en/hud/r/10.bmp");
	m->anim.r[17] = SDL_LoadBMP("../resources/en/hud/r/11.bmp");
	m->anim.r[18] = SDL_LoadBMP("../resources/en/hud/r/12.bmp");
	m->anim.r[19] = SDL_LoadBMP("../resources/en/hud/r/13.bmp");
	while (++i < 20)
		if (m->anim.r[i] == NULL)
			exit(-11);
}

void			ft_load_shoot(t_main *m, int i)
{
	if (!(m->anim.bullet = SDL_LoadBMP("../resources/en/hud/stats/bullet.bmp")))
		exit(-11);
	m->anim.s[0] = SDL_LoadBMP("../resources/en/hud/gun/s1.bmp");
	m->anim.s[1] = SDL_LoadBMP("../resources/en/hud/gun/s2.bmp");
	m->anim.s[2] = SDL_LoadBMP("../resources/en/hud/gun/s3.bmp");
	while (++i < 3)
		if (m->anim.s[i] == NULL)
			exit(-11);
}

void			ft_load_reload_2(t_main *m, int i)
{
	m->anim.r[20] = SDL_LoadBMP("../resources/en/hud/r/14.bmp");
	m->anim.r[21] = SDL_LoadBMP("../resources/en/hud/r/15.bmp");
	m->anim.r[22] = SDL_LoadBMP("../resources/en/hud/r/16.bmp");
	m->anim.r[23] = SDL_LoadBMP("../resources/en/hud/r/17.bmp");
	m->anim.r[24] = SDL_LoadBMP("../resources/en/hud/r/18.bmp");
	m->anim.r[25] = SDL_LoadBMP("../resources/en/hud/r/19.bmp");
	m->anim.r[26] = SDL_LoadBMP("../resources/en/hud/r/20.bmp");
	m->anim.r[27] = SDL_LoadBMP("../resources/en/hud/r/21.bmp");
	m->anim.r[28] = SDL_LoadBMP("../resources/en/hud/r/22.bmp");
	m->anim.r[29] = SDL_LoadBMP("../resources/en/hud/r/23.bmp");
	m->anim.r[30] = SDL_LoadBMP("../resources/en/hud/r/24.bmp");
	m->anim.r[31] = SDL_LoadBMP("../resources/en/hud/r/25.bmp");
	m->anim.r[32] = SDL_LoadBMP("../resources/en/hud/r/26.bmp");
	m->anim.r[33] = SDL_LoadBMP("../resources/en/hud/r/27.bmp");
	m->anim.r[34] = SDL_LoadBMP("../resources/en/hud/r/28.bmp");
	m->anim.r[35] = SDL_LoadBMP("../resources/en/hud/r/29.bmp");
	m->anim.r[36] = SDL_LoadBMP("../resources/en/hud/r/30.bmp");
	m->anim.r[37] = SDL_LoadBMP("../resources/en/hud/r/31.bmp");
	m->anim.r[38] = SDL_LoadBMP("../resources/en/hud/r/32.bmp");
	m->anim.r[39] = SDL_LoadBMP("../resources/en/hud/r/33.bmp");
	while (++i < 40)
		if (m->anim.r[i] == NULL)
			exit(-11);
}

void			ft_load_texture(t_main *m)
{
	if (!(m->sky.sky = SDL_LoadBMP("../resources/en/sky/sky.bmp")))
		print_error(BAD_SKYBOX);
	if (!(m->sdl.font = TTF_OpenFont("../resources/en/font/ArialBold.ttf", 18)))
		exit(-10);
	if (!(m->texture[0] = SDL_LoadBMP("../resources/en/text/1.bmp")))
		exit(-11);
	if (!(m->texture[1] = SDL_LoadBMP("../resources/en/text/2.bmp")))
		exit(-11);
	if (!(m->texture[2] = SDL_LoadBMP("../resources/en/text/3.bmp")))
		exit(-11);
	if (!(m->texture[3] = SDL_LoadBMP("../resources/en/text/4.bmp")))
		exit(-11);
	if (!(m->texture[4] = SDL_LoadBMP("../resources/en/text/5.bmp")))
		exit(-11);
	if (!(m->texture[5] = SDL_LoadBMP("../resources/en/text/6.bmp")))
		exit(-11);
	if (!(m->sprite.ch = SDL_LoadBMP("../resources/en/ch/chr.bmp")))
		exit(-11);
	if (!(m->pict.end = SDL_LoadBMP("../resources/en/scrns/end.bmp")) ||
		!(m->pict.start = SDL_LoadBMP("../resources/en/scrns/start.bmp")))
		exit(3);
}

void			ft_load_music(t_main *m)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ||
		!(m->music.audio = Mix_LoadMUS("../resources/en/music/main.wav")) ||
		!(m->music.gunshot = Mix_LoadWAV("../resources/en/music/gunshot.wav")))
	{
		ft_putendl((char *)SDL_GetError());
		exit(2);
	}
	Mix_PlayMusic(m->music.audio, 10);
}
