/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:32:03 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 18:32:05 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_move_add(t_main *m, t_vertex *pos,
				t_vertex pos_vec, t_colll coco)
{
	if (m->cols.flag_x != 1)
		pos->x = m->player.pos.x + pos_vec.x * coco.move;
	else
		pos->x = m->player.pos.x;
	if (m->cols.flag_y != 1)
		pos->y = m->player.pos.y + pos_vec.y * coco.move;
	else
		pos->y = m->player.pos.y;
}

void			ft_coll1(t_main *m, t_vertex pos_vec, t_colll *coco,
				t_cols_wall *lst)
{
	t_vertex	res;

	if (m->cols.flag_x == 0)
	{
		m->pos.x = m->player.pos.x + pos_vec.x * coco->move;
		m->pos.y = m->player.pos.y;
		coco->dist = fabs(ft_get_dist_cols(lst, m->cols, m->pos));
		res = ft_intersection(m->player.pos, m->pos, lst->start, lst->end);
		if (coco->dist <= 0.4 && lst->type == -1)
			m->cols.flag_x = 1;
	}
	if (m->cols.flag_y == 0)
	{
		m->pos.x = m->player.pos.x;
		m->pos.y = m->player.pos.y + pos_vec.y * coco->move;
		coco->dist = fabs(ft_get_dist_cols(lst, m->cols, m->pos));
		res = ft_intersection(m->player.pos, m->pos, lst->start, lst->end);
		if (coco->dist <= 0.4 && lst->type == -1)
			m->cols.flag_y = 1;
	}
}

void			ft_coll2(t_main *m, t_vertex pos_vec, t_colll *coco,
				t_cols_wall *lst)
{
	t_vertex	res;

	if (m->cols.flag_x == 0)
	{
		m->pos.x = m->player.pos.x + pos_vec.x * coco->move;
		m->pos.y = m->player.pos.y;
		coco->dist = fabs(ft_get_dist_cols(lst, m->cols, m->pos));
		res = ft_intersection(m->player.pos, m->pos, lst->start, lst->end);
		if (coco->dist <= 0.4)
			if (m->player.pos.z + 2 + m->player.jump_h <
					m->sector[lst->type].heigth.floor)
				m->cols.flag_x = 1;
	}
	if (m->cols.flag_y == 0)
	{
		m->pos.x = m->player.pos.x;
		m->pos.y = m->player.pos.y + pos_vec.y * coco->move;
		coco->dist = fabs(ft_get_dist_cols(lst, m->cols, m->pos));
		res = ft_intersection(m->player.pos, m->pos, lst->start, lst->end);
		if (coco->dist <= 0.4)
			if (m->player.pos.z + 2 + m->player.jump_h <
					m->sector[lst->type].heigth.floor)
				m->cols.flag_y = 1;
	}
}
