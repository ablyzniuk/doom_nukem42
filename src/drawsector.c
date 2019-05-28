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
	int32_t		sv_start;
	int32_t		sv_end;

	sv_end = wall.end;
	if (ray.num_sect != m->sector[ray.num_sect].transit[ray.wall_sect])
	{
		while (wall.end < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.end, 0xFFFFFF / (ray.num_sect + 2));
			wall.end++;
		}
		return (sv_end < wall.buffer_draw ? sv_end : wall.buffer_draw);
	}
	return (wall.buffer_draw);
}

int32_t	ft_draw_wall(t_main *m, t_ray ray, t_heigth_wall wall)
{
	int32_t		sv_start;
	int32_t		sv_end;

	if (m->sector[ray.num_sect].transit[ray.wall_sect] == -1)
	{
		while (wall.start < wall.end && wall.start < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.start, 0xFFFFFF / (ray.num_sect + 3));
			wall.start++;
		}
		return (wall.start < wall.buffer_draw ? wall.start : wall.buffer_draw);
	}
	if (m->sector[ray.num_sect].heigth.floor < m->sector[ray.old_num_sect].heigth.floor)
	{
		sv_end = wall.end;
		while (wall.end < wall.buffer_draw)
		{
			ft_put_pixel(m, ray.w, wall.end, 0xFFFFFF / (ray.num_sect + 4));
			wall.end++;
		}
		return (sv_end < wall.buffer_draw ? sv_end : wall.buffer_draw);
	}
	return (wall.buffer_draw);
}

int32_t	ft_draw_cell(t_main *m, t_ray ray, t_heigth_wall wall)
{
	int32_t		sv_start;
	int32_t		sv_end;
	int k;
	
	k = 0;
	if (ray.num_sect != m->sector[ray.num_sect].transit[ray.wall_sect])
	{
		sv_start = wall.start;
		while (wall.start > 0)
		{
			ft_put_pixel(m, ray.w, wall.start, 0x00f00f / (ray.num_sect + 10));
			wall.start--;
		}
		return (wall.buffer_draw);
	}
	return (wall.buffer_draw);
}