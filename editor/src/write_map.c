/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 10:44:12 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:44:15 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				write_vertex_general(t_vertex *vertex, int fd)
{
	int				y;
	t_vertex		*pvertex;

	pvertex = vertex;
	while (pvertex)
	{
		ft_putstr_fd("vertex\t", fd);
		ft_putnbr_fd(pvertex->y / 3, fd);
		ft_putchar_fd('\t', fd);
		y = pvertex->y;
		while (pvertex && pvertex->y == y)
		{
			ft_putnbr_fd(pvertex->x / 3, fd);
			if (pvertex->next != NULL && pvertex->next->y == y)
				ft_putchar_fd(' ', fd);
			pvertex = pvertex->next;
		}
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
}

void				write_sect(t_sect *p_sect, t_vertex *all_vertex, int fd)
{
	t_sect			*sect;
	t_vertex		*vertex;

	sect = p_sect;
	while (sect)
	{
		vertex = sect->vertex;
		if (vertex)
		{
			ft_putstr_fd("sector\t", fd);
			ft_putnbr_fd(sect->hfloor, fd);
			ft_putchar_fd(' ', fd);
			ft_putnbr_fd(sect->hceil, fd);
			ft_putchar_fd('\t', fd);
			write_vertex(sect, all_vertex, fd);
			ft_putchar_fd('\n', fd);
		}
		sect = sect->next;
	}
}

void				write_player(t_edit *edit, int fd)
{
	ft_putstr_fd("\nplayer\t", fd);
	ft_putnbr_fd(edit->player.position.x / 3, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(edit->player.position.y / 3, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\t', fd);
	ft_putnbr_fd(edit->player.current_sect, fd);
	ft_putstr_fd("\n\n", fd);
}

void				write_point(char *str, t_point *ppoint, int fd)
{
	t_point			*point;

	point = ppoint;
	while (point)
	{
		ft_putstr_fd(str, fd);
		ft_putnbr_fd(point->position.x / 3, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(point->position.y / 3, fd);
		ft_putchar_fd('\t', fd);
		ft_putnbr_fd(point->current_sect, fd);
		ft_putchar_fd('\n', fd);
		point = point->next;
	}
	ft_putchar_fd('\n', fd);
}

void				write_map(t_edit *edit, int fd)
{
	write_vertex_general(edit->vertex, fd);
	write_sect(edit->sect, edit->vertex, fd);
	write_player(edit, fd);
	if (edit->enemy != NULL)
		write_point("enemy\t", edit->enemy, fd);
	if (edit->objects != NULL)
		write_point("decor\t", edit->objects, fd);
}
