/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:25 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:38 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				pick_texture(t_edit **edit, int x, int y)
{
	t_vertex		point;
	int				inside;

	point.x = x;
	point.y = y;
	if ((*edit)->ass_tex == NULL)
	{
		inside = is_inside_sect((*edit), point);
		if (inside != -1)
			(*edit)->ass_tex = get_sect_num(edit, inside);
	}
	else if ((*edit)->index == -1)
		draw_bmp((*edit)->sdl, (*edit)->text[1], WIN_H - SETT_PAD, SETT_PAD);
}

void				edit_ceil_floor(t_edit **edit, int x, int y)
{
	t_vertex		point;
	int				inside;

	point.x = x;
	point.y = y;
	(*edit)->ass_tex = NULL;
	if ((*edit)->ass_tex == NULL)
	{
		inside = is_inside_sect((*edit), point);
		if (inside != -1)
			(*edit)->ass_tex = get_sect_num(edit, inside);
	}
}
