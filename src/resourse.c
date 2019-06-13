/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resourse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:13:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/04 14:21:19 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    ft_load_texture(t_main *m)
{

	m->sky.sky = SDL_LoadBMP("resourse/sky/sky.bmp");
	if (m->sky.sky == NULL)
		print_error(BAD_SKYBOX);
	m->sdl.font = TTF_OpenFont("resourse/font/ArialBold.ttf", 18);
	if (m->sdl.font == NULL)
		exit(-10);
	m->texture[0] = SDL_LoadBMP("resourse/textures/2.bmp");
	if (m->texture[0] == NULL)
		exit(-11);
	m->texture[1] = SDL_LoadBMP("resourse/textures/1.bmp");
	if (m->texture[1] == NULL)
		exit(-11);
	m->texture[2] = SDL_LoadBMP("resourse/textures/3.bmp");
	if (m->texture[2] == NULL)
		exit(-11);
	m->texture[3] = SDL_LoadBMP("resourse/textures/4.bmp");
	if (m->texture[3] == NULL)
		exit(-11);
}
