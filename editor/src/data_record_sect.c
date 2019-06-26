/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_record_sect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:07:58 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:16 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sect				*new_sect(void)
{
	static int		number_of_sect = 0;
	t_sect			*sect;

	sect = (t_sect *)ft_memalloc(sizeof(t_sect));
	sect->number = number_of_sect;
	sect->is_child = -1;
	sect->hceil = 20;
	sect->hfloor = 0;
	sect->texture[0] = 0;
	sect->texture[1] = -2;
	sect->texture[2] = 5;
	number_of_sect++;
	return (sect);
}

t_sect				*get_sect_num(t_edit **edit, int num)
{
	t_sect			*psect;

	psect = (*edit)->sect;
	while (psect->next)
	{
		if (psect->number == num)
			return (psect);
		psect = psect->next;
	}
	return (psect);
}

t_sect				*get_last_sect(t_edit **edit)
{
	t_sect			*psect;

	if (!(*edit)->sect)
	{
		(*edit)->sect = new_sect();
		return ((*edit)->sect);
	}
	psect = (*edit)->sect;
	while (psect->next)
		psect = psect->next;
	return (psect);
}

t_vertex			*get_vertex(t_edit **edit, int x, int y)
{
	t_vertex		*new;

	x = (x / (*edit)->zoom) * (*edit)->zoom;
	y = (y / (*edit)->zoom) * (*edit)->zoom;
	new = is_present((*edit)->vertex, x, y);
	if (!new)
	{
		new = new_vertex(x, y);
		add_vertex(&(*edit)->vertex, new, 1);
	}
	return (new);
}

void				sect_record(t_edit **edit, int x, int y)
{
	t_vertex		*new;
	t_vertex		*new_to_sect;
	t_sect			*sect;

	new = get_vertex(edit, x, y);
	sect = get_last_sect(edit);
	if (cmp_vertex(sect->vertex, new))
	{
		sect->vertex_count = count_vertex(sect->vertex);
		sect->is_portal = (int *)ft_memalloc(sizeof(int) * sect->vertex_count);
		sect->is_portal = ft_memset(sect->is_portal, -1,
			sizeof(int) * sect->vertex_count);
		if (sect->is_child != -1)
			sect->is_portal[1] = sect->is_child;
		sect->next = new_sect();
		(*edit)->sect_is_closed = 1;
	}
	else
	{
		new_to_sect = (t_vertex *)ft_memalloc(sizeof(t_vertex));
		new_to_sect = ft_memcpy(new_to_sect, new, sizeof(new));
		add_vertex(&sect->vertex, new_to_sect, 0);
		(*edit)->sect_is_closed = 0;
	}
}
