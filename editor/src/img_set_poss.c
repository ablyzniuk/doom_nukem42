/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_poss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:56:26 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:33 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_img				init_img(t_edit **edit)
{
	t_img			img;

	img.flag = 0;
	img.move = (*edit)->bmp[0]->w + SETT_PAD / 2;
	img.x_init = WIN_W - (img.move * 2) - 10;
	img.x_start = WIN_W - (img.move * 2) - 10;
	img.y_start = SETT_PAD;
	(*edit)->x_bounds = img.x_start - SETT_PAD;
	return (img);
}

void				set_icons(t_edit **edit, t_img *img, int tex, int i)
{
	int				width;
	int				height;

	width = (*edit)->bmp[0]->w;
	height = (*edit)->bmp[0]->h;
	(*edit)->pos_start[i][0] = img->x_start;
	(*edit)->pos_start[i][1] = img->y_start + tex;
	(*edit)->pos_end[i][0] = img->x_start + width;
	(*edit)->pos_end[i][1] = img->y_start + height + tex;
	img->x_start += img->move;
	if (img->x_start + img->move >= WIN_W)
	{
		img->x_start = img->x_init;
		img->y_start += img->move;
	}
}

void				set_poss(t_edit **edit)
{
	int				i;
	int				tex;
	t_img			img;

	i = -1;
	img = init_img(edit);
	tex = img.move;
	while (++i < NUM_TEX_P)
	{
		if (i >= NUM_TEX_T)
			set_icons(edit, &img, tex, i);
		else
			set_icons(edit, &img, 0, i);
	}
}
