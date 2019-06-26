/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:19:12 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:19:14 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void				bullet_manage(t_main *m)
{
	int				i;
	int				to_display;

	i = 0;
	to_display = m->player.ammo;
	while (++i <= to_display)
		draw_bmp(m, m->anim.bullet, 84, 44 * i);
}

void				h_draw_gun(t_main *m, int *tick, int *time, int *i)
{
	if (*time == 0)
		*time = *tick;
	if (*tick - *time > 300)
		(*i)++;
	if (*tick - *time > 300 && *i == 40)
	{
		*time = 0;
		(*i) = 1;
		m->anim.curr = 0;
		m->player.ammo = 10;
	}
	draw_bmp(m, m->anim.r[*i], 0, 0);
}

void				k_draw_gun(t_main *m, int *tick, int *time, int *i)
{
	if (*time == 0)
		*time = *tick;
	if (*tick - *time > 300)
		(*i)++;
	if (*tick - *time > 300 && *i == 3)
	{
		if (m->spr_data.anglee < 3.0)
			m->eventcall.eee = 1;
		*time = 0;
		(*i) = 1;
		m->anim.curr = 0;
		m->player.ammo--;
	}
	draw_bmp(m, m->anim.s[*i], 0, 0);
}

void				draw_gun(t_main *m)
{
	static int		i = 1;
	static int		time = 0;
	int				tick;

	tick = SDL_GetTicks();
	if (m->anim.curr == 3)
		h_draw_gun(m, &tick, &time, &i);
	else if (m->anim.curr == 2)
		k_draw_gun(m, &tick, &time, &i);
	else
		draw_bmp(m, m->anim.r[0], 0, 0);
}
