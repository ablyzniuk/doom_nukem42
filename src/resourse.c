/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resourse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:13:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/07 18:08:29 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    ft_load_texture(t_main *m)
{

	m->sky.sky = SDL_LoadBMP("resourse/sky/sky.bmp");
	printf("%s\n", SDL_GetError());
	if (m->sky.sky == NULL)
		print_error(BAD_SKYBOX);
	m->sdl.font = TTF_OpenFont("resourse/font/ArialBold.ttf", 18);
	if (m->sdl.font == NULL)
		exit(-10);
}