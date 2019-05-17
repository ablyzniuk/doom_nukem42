/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:19:13 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/08 21:50:37 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int ft_collision(t_main *m, t_vertex start, t_vertex end)
{
	size_t			wall_sect;
	size_t			k;
	int			flag;
	int			he;
	t_vertex	res;
	t_vertex	wall_start;
	t_vertex	wall_end;

	k = 0;
	wall_sect = 0;
	flag = 0;
	while (wall_sect < m->sector[m->player.sector].vertex_arr_len)
	{
		if (wall_sect == 0)
			k = m->sector[m->player.sector].vertex_arr_len - 1;
		else
			k = wall_sect - 1;
		wall_start.x = m->sector[m->player.sector].vertex[k][1];
		wall_start.y = m->sector[m->player.sector].vertex[k][0];
		wall_end.x = m->sector[m->player.sector].vertex[wall_sect][1];
		wall_end.y = m->sector[m->player.sector].vertex[wall_sect][0];
		res = ft_intersection(start, end, wall_start, wall_end);
		if (m->sector[m->player.sector].transit[wall_sect] != -1 && res.z != -1)
		{
			he = m->sector[m->sector[m->player.sector].transit[wall_sect]].heigth.floor;
			if (m->player.pos.z + 2 >= he)
				flag = 1;
			break;
		}
		else if (res.z != -1 && m->sector[m->player.sector].transit[wall_sect] == -1)
			return (-1);
		wall_sect++;
	}
	if (res.z == -1)
		return (1);
	if (flag == 1)
	{
		m->player.sector = m->sector[m->player.sector].transit[wall_sect];
		m->player.pos.z = he;
		return (1);
	}
	return (-1);
	return (0);
}