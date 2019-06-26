/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_cols_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:02:49 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:17:52 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_get_wall(t_main *m, t_cols_wall *cols,
									size_t wall_sect, size_t sect)
{
	size_t		k;

	if (wall_sect == 0)
		k = m->sector[sect].vertex_arr_len - 1;
	else
		k = wall_sect - 1;
	cols->sector = sect;
	cols->num_wall = wall_sect;
	cols->type = m->sector[sect].transit[wall_sect];
	cols->start.x = m->sector[sect].vertex[k][1];
	cols->start.y = m->sector[sect].vertex[k][0];
	cols->end.x = m->sector[sect].vertex[wall_sect][1];
	cols->end.y = m->sector[sect].vertex[wall_sect][0];
}

void			ft_add_cols_next_next(t_main *m, size_t old_sect, size_t sect)
{
	size_t		wall_sect;
	t_cols_wall	*lst;

	wall_sect = 0;
	while (wall_sect < m->sector[sect].vertex_arr_len)
	{
		if (m->sector[sect].transit[wall_sect] == -1)
		{
			if (m->sector[old_sect].cols == NULL)
			{
				m->sector[old_sect].cols = ft_cr_new_list();
				ft_get_wall(m, m->sector[old_sect].cols, wall_sect, sect);
			}
			else
			{
				lst = ft_cr_new_list();
				ft_get_wall(m, lst, wall_sect, sect);
				ft_lst_add_back(m->sector[old_sect].cols, lst);
			}
		}
		wall_sect++;
	}
}

void			ft_add_cols_next(t_main *m, size_t old_sect, size_t sect)
{
	size_t		wall_sect;
	t_cols_wall	*lst;

	wall_sect = 0;
	while (wall_sect < m->sector[sect].vertex_arr_len)
	{
		if (m->sector[sect].transit[wall_sect] == -1)
		{
			if (m->sector[old_sect].cols == NULL)
			{
				m->sector[old_sect].cols = ft_cr_new_list();
				ft_get_wall(m, m->sector[old_sect].cols, wall_sect, sect);
			}
			else
			{
				lst = ft_cr_new_list();
				ft_get_wall(m, lst, wall_sect, sect);
				ft_lst_add_back(m->sector[old_sect].cols, lst);
			}
		}
		else
			ft_add_cols_next_next(m, old_sect,
					m->sector[sect].transit[wall_sect]);
		wall_sect++;
	}
}

void			ft_add_cols(t_main *m, size_t sect, size_t wall_sect)
{
	t_cols_wall	*lst;

	if (m->sector[sect].cols == NULL)
	{
		m->sector[sect].cols = ft_cr_new_list();
		ft_get_wall(m, m->sector[sect].cols, wall_sect, sect);
	}
	else
	{
		lst = ft_cr_new_list();
		ft_get_wall(m, lst, wall_sect, sect);
		ft_lst_add_back(m->sector[sect].cols, lst);
	}
	if (m->sector[sect].transit[wall_sect] != -1)
		ft_add_cols_next(m, sect, m->sector[sect].transit[wall_sect]);
}

void			ft_cr_cols_init(t_main *m)
{
	size_t		sect;
	size_t		wall_sect;

	sect = 0;
	while (sect < m->sum_sect)
	{
		wall_sect = 0;
		while (wall_sect < m->sector[sect].vertex_arr_len)
		{
			ft_add_cols(m, sect, wall_sect);
			wall_sect++;
		}
		sect++;
	}
}
