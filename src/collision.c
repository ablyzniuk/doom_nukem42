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

double	ft_dist(t_vertex start, t_vertex end)
{
	double	dist;

	dist = sqrt(pow(end.x - start.x, 2.0) + pow(end.y - start.y, 2.0));
	return (dist);
}

double	ft_dist_cord(double x1, double y1, double x2, double y2)
{
	double	dist;

	dist = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
	return (dist);
}

double	ft_get_dist_cols(t_main *m, t_cols_wall *lst, t_collision cols, t_vertex pos_vec)
{
	double		a;
	double		b;
	double		c;
	double		dist;
	double		t;

	cols.wall_len = ft_dist(lst->start, lst->end);
	cols.len_start = ft_dist(lst->start, pos_vec);
	cols.len_end = ft_dist(lst->end, pos_vec);
	if (cols.len_start > ft_dist_cord(cols.len_end, cols.wall_len, 0, 0)
	|| cols.len_end > ft_dist_cord(cols.len_start, cols.wall_len, 0, 0))
		return (-1);
	a = lst->end.y - lst->start.y;
	b = lst->start.x - lst->end.x;
	c = -lst->start.x * (lst->end.y - lst->start.y)
	+ lst->start.y * (lst->end.x - lst->start.x);
	if (c > 0)
	{
		a = -a;
		b = -b;
		c = -c;
	}
	t = ft_dist_cord(a, b, 0, 0);
	dist = (a * pos_vec.x + b * pos_vec.y + c) / t;
	return (dist);
}

int32_t	ft_get_tp(t_main *m, t_vertex vec)
{
	t_cols_wall	*lst;
	t_vertex	res;

	lst = m->sector[m->player.sector].cols;
	if (vec.x != 0 && vec.y != 0)
		while (lst)
		{
			if (lst->type != -1)
			{
				res = ft_intersection(m->player.pos, vec, lst->start, lst->end);
				if (res.z != -1)
					return (lst->type);
			}
			lst = lst->next;
		}
	return (-1);
}

int32_t ft_collision(t_main *m, t_vertex pos_vec, double move)
{
	t_collision	cols;
	t_cols_wall	*lst;
	t_vertex	pos;
	t_vertex	res;
	int32_t		tp;
	double		dist;

	lst = m->sector[m->player.sector].cols;
	cols.flag_x = 0;
	cols.flag_y = 0;
	tp = -1;
	while (lst)
	{
		if (lst->type == -1)
		{
			if (cols.flag_x == 0)
			{
				pos.x = m->player.pos.x + pos_vec.x * move;
				pos.y = m->player.pos.y;
				dist = fabs(ft_get_dist_cols(m, lst, cols, pos));
				res = ft_intersection(m->player.pos, pos, lst->start, lst->end);
				if (dist <= 0.4 && lst->type == -1)
						cols.flag_x = 1;
			}
			if (cols.flag_y == 0)
			{
				pos.x = m->player.pos.x;
				pos.y = m->player.pos.y + pos_vec.y * move;
				dist = fabs(ft_get_dist_cols(m, lst, cols, pos));
				res = ft_intersection(m->player.pos, pos, lst->start, lst->end);
				if (dist <= 0.4 && lst->type == -1)
					cols.flag_y = 1;
			}
		}
		else if (lst->type != -1)
		{
			if (cols.flag_x == 0)
			{
				pos.x = m->player.pos.x + pos_vec.x * move;
				pos.y = m->player.pos.y;
				dist = fabs(ft_get_dist_cols(m, lst, cols, pos));
				res = ft_intersection(m->player.pos, pos, lst->start, lst->end);
				if (dist <= 0.4)
					if (m->player.pos.z + 2 + m->player.jump_h < m->sector[lst->type].heigth.floor)
						cols.flag_x = 1;
			}
			if (cols.flag_y == 0)
			{
				pos.x = m->player.pos.x;
				pos.y = m->player.pos.y + pos_vec.y * move;
				dist = fabs(ft_get_dist_cols(m, lst, cols, pos));
				res = ft_intersection(m->player.pos, pos, lst->start, lst->end);
				if (dist <= 0.4)
					if (m->player.pos.z + 2 + m->player.jump_h < m->sector[lst->type].heigth.floor)
						cols.flag_y = 1;
			}
		}
		
		lst = lst->next;
	}
	if (cols.flag_x != 1)
		pos.x = m->player.pos.x + pos_vec.x * move;
	else
		pos.x = m->player.pos.x;
	if (cols.flag_y != 1)
		pos.y = m->player.pos.y + pos_vec.y * move;
	else
		pos.y = m->player.pos.y;
	tp = ft_get_tp(m, pos);
	if (tp != -1)
		m->player.sector = tp;
	m->player.pos.x = pos.x;
	m->player.pos.y = pos.y;
	return (1);
}