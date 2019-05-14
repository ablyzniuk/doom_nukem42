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

int		ft_collision(t_main *m, t_vertex start, t_vertex end)
{
//	int			wall_sect;
//	int			k;
//	int			flag;
//	int			he;
//	t_vertex	res;
//
//	k = 0;
//	wall_sect = 0;
//	flag = 0;
//	while (wall_sect < 4)
//	{
//		k = wall_sect + 1;
//			if (k == 4)
//				k = 0;
//		res = ft_intersection(start, end, m->vertex[m->sector[m->player.sector]->vertex[wall_sect]], m->vertex[m->sector[m->player.sector]->vertex[k]]);
//		if (m->sector[m->player.sector]->typewall[wall_sect] != -1 && res.z != -1)
//		{
//			he = m->sector[m->sector[m->player.sector]->typewall[wall_sect]]->heigth.floor;
//			if (m->player.pos.z + 2 >= he)
//				flag = 1;
//			break;
//		}
//		else if (res.z != -1 && m->sector[m->player.sector]->typewall[wall_sect] == -1)
//			return (-1);
//		wall_sect++;
//	}
//	if (res.z == -1)
//		return (1);
//	if (flag == 1)
//	{
//		m->player.sector = m->sector[m->player.sector]->typewall[wall_sect];
//		return (1);
//	}
//	return (-1);
	return (0);
}