/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:29 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:40 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				set_player(t_edit **edit, int x, int y)
{
	int				current_sect;
	t_point			player;

	player.position.x = x;
	player.position.y = y;
	current_sect = is_inside_sect((*edit), player.position);
	if (current_sect != -1)
	{
		player.health = 100;
		player.current_sect = current_sect;
		(*edit)->player = player;
	}
}

void				set_enemy(t_edit **edit, int x, int y)
{
	int				current_sect;
	t_point			*enemy;
	t_point			*it;

	enemy = (t_point *)ft_memalloc(sizeof(t_point));
	enemy->position.x = x;
	enemy->position.y = y;
	current_sect = is_inside_sect((*edit), enemy->position);
	if (current_sect != -1)
	{
		enemy->current_sect = current_sect;
		enemy->is_directional = 1;
		enemy->health = 100;
		if ((*edit)->enemy == NULL)
			(*edit)->enemy = enemy;
		else
		{
			it = (*edit)->enemy;
			while (it->next != NULL)
				it = it->next;
			it->next = enemy;
		}
		return ;
	}
	free(enemy);
}

void				set_obj(t_edit **edit, int x, int y)
{
	int				current_sect;
	t_point			*obj;
	t_point			*it;

	obj = (t_point *)ft_memalloc(sizeof(t_point));
	obj->position.x = x;
	obj->position.y = y;
	current_sect = is_inside_sect((*edit), obj->position);
	if (current_sect != -1)
	{
		obj->current_sect = current_sect;
		obj->is_directional = 0;
		obj->health = 42;
		if ((*edit)->objects == NULL)
			(*edit)->objects = obj;
		else
		{
			it = (*edit)->objects;
			while (it->next != NULL)
				it = it->next;
			it->next = obj;
		}
		return ;
	}
	free(obj);
}
