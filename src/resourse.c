/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resourse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:13:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 14:13:33 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    ft_load_texture(t_main *m)
{

	m->sky.sky = SDL_LoadBMP("resourse/sky/sky.bmp");
	printf("%s\n", SDL_GetError());
	if (m->sky.sky == NULL)
	{
		printf("Error Load Skybox!\n");
		exit(0);
	}
}