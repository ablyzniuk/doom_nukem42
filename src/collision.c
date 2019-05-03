/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:19:13 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/03 16:19:15 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_collision(t_main *m, t_vertex start, t_vertex end)
{
	int			wall_sect;
	int			k;
	t_vertex	res;

	k = 0;
	wall_sect = 0;
	while (wall_sect < 4)
	{
		k = wall_sect + 1;
			if (k == 4)
				k = 0;
		res = ft_intersection(start, end, m->vertex[m->sector[m->player.sector]->vertex[wall_sect]], m->vertex[m->sector[m->player.sector]->vertex[k]]);
		if (res.z != -1)
			break;
		wall_sect++;
	}
	if (res.z != -1.0 && m->sector[m->player.sector]->typewall[wall_sect] == -1)
		return (-1);
	else if (res.z != -1 && m->sector[m->player.sector]->typewall[wall_sect] != -1)
	{
		m->player.sector = m->sector[m->player.sector]->typewall[wall_sect];
		return (1);
	}
	else
		return (0);
}