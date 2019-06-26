/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:06 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:08 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_key_exit(t_main *m, int *run)
{
	if (m->sdl.event.type == SDL_QUIT ||
		(SDL_SCANCODE_ESCAPE == m->sdl.event.key.keysym.scancode))
		*run = 0;
}
