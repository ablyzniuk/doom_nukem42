/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:19:09 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/06 12:19:11 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int32_t	ft_draw_floor(t_main *m, t_ray ray, t_heigth_wall wall)
{
	int32_t	sv_start;
	int32_t	sv_end;

	sv_start = wall.start;
	sv_end = wall.end;
	if (wall.w != ray.w)//   пол сектора
	{
		while (wall.end < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.end, 0xffffa2);
			wall.end++;
		}
		return (sv_end);
	}
	if (m->sector[ray.num_sect].heigth.floor ==
	m->sector[m->sector[ray.num_sect].transit[ray.wall_sect]].heigth.floor)
	{
		while (wall.end < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.end,  0xffffa2);
			wall.end++;
		}
		return (sv_end < wall.buffer_draw ? sv_end : wall.buffer_draw);
	}
	if (m->sector[ray.num_sect].heigth.floor >
	m->sector[ray.old_num_sect].heigth.floor && ray.num_sect != ray.old_num_sect && 0)
	{
		while (wall.end < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.end, 0xffffa2);
			wall.end++;
		}
		return (sv_end < wall.buffer_draw ? sv_end : wall.buffer_draw);
	}
	return (wall.buffer_draw);
}

int32_t	ft_draw_wall(t_main *m, t_ray ray, t_heigth_wall wall)
{
	int32_t	sv_start;
	int32_t	sv_end;

	sv_start = wall.start;
	sv_end	= wall.end;
	if (m->sector[ray.num_sect].transit[ray.wall_sect] == -1)
	{
		while (wall.start < wall.end && wall.start < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.start, 0xffffff / (ray.num_sect + 1));
			wall.start++;
		}
	return (sv_start < wall.buffer_draw ? sv_start : wall.buffer_draw);
	}
	if (m->sector[ray.num_sect].heigth.floor <
	m->sector[m->sector[ray.num_sect].transit[ray.wall_sect]].heigth.floor)
	{
		wall.start = wall.end - HE_P * abs(m->sector[ray.num_sect].heigth.floor
		- m->sector[m->player.sector].heigth.floor)
		/ ray.camdist;
		sv_start = wall.start;
		while (wall.start < wall.end && wall.start < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.start, 0xffffff / (ray.num_sect + 1));
			wall.start++;
		}
		return (sv_start < wall.buffer_draw ? sv_start : wall.buffer_draw);
	}
	return (wall.buffer_draw);
}

int32_t	ft_draw_cell(t_main *m, t_ray ray, t_heigth_wall wall)
{
	return (wall.buffer_draw);
}