/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_record_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:08:36 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:19 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int					count_vertex(t_vertex *pvertex)
{
	int				count;
	t_vertex		*vertex;

	count = 0;
	vertex = pvertex;
	while (vertex)
	{
		count++;
		vertex = vertex->next;
	}
	return (count);
}

t_vertex			*new_vertex(int x, int y)
{
	t_vertex		*new;

	new = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	new->x = x;
	new->y = y;
	return (new);
}

void				add_vertex(t_vertex **vertex, t_vertex *to_add, int count)
{
	static int		number = 0;
	t_vertex		*pvertex;

	if (count)
	{
		to_add->number = number;
		number++;
	}
	if (!(*vertex))
		(*vertex) = to_add;
	else
	{
		pvertex = (*vertex);
		while (pvertex->next)
			pvertex = pvertex->next;
		pvertex->next = to_add;
	}
}

t_vertex			*is_present(t_vertex *vertex, int x, int y)
{
	t_vertex		*pvertex;

	if (!vertex)
		return (NULL);
	pvertex = vertex;
	while (pvertex)
	{
		if (pvertex->x == x && pvertex->y == y)
			return (pvertex);
		pvertex = pvertex->next;
	}
	return (NULL);
}

int					cmp_vertex(t_vertex *first, t_vertex *last)
{
	if (!first || !last)
		return (0);
	if (first->x == last->x && first->y == last->y)
		return (1);
	return (0);
}
