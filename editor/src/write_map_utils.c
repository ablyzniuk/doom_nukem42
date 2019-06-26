/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 10:44:24 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:44:31 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					search_vertex(t_vertex *p_vertex, t_vertex *to_find)
{
	t_vertex		*vertex;

	vertex = p_vertex;
	while (vertex)
	{
		if (vertex->y == to_find->y && vertex->x == to_find->x)
			return (vertex->number);
		vertex = vertex->next;
	}
	return (-1);
}

void				write_portals(t_sect *sect, int fd)
{
	int				i;

	i = 0;
	while (i < sect->vertex_count)
	{
		ft_putnbr_fd(sect->is_portal[i], fd);
		if (i + 1 < sect->vertex_count)
			ft_putchar_fd(' ', fd);
		i++;
	}
}

void				write_textures(t_sect *sect, int fd)
{
	int				i;

	i = 0;
	while (i < TEX)
	{
		ft_putnbr_fd(sect->texture[i], fd);
		if (i + 1 < TEX)
			ft_putchar_fd(' ', fd);
		i++;
	}
}

void				write_vertex(t_sect *sect, t_vertex *all_vertex, int fd)
{
	int				pos;
	t_vertex		*vertex;

	vertex = sect->vertex;
	while (vertex)
	{
		pos = search_vertex(all_vertex, vertex);
		ft_putnbr_fd(pos, fd);
		if (vertex->next)
			ft_putchar_fd(' ', fd);
		vertex = vertex->next;
	}
	ft_putstr_fd("\t", fd);
	write_portals(sect, fd);
	ft_putchar_fd('\t', fd);
	write_textures(sect, fd);
}
