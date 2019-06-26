/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:12 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:14 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void				tmp_list(t_list **lst, const void *content,
							const size_t content_size)
{
	t_list			*tmp;

	if (!*lst)
		*lst = ft_lstnew(content, content_size);
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
}

size_t				two_dim_len(char **array)
{
	size_t			size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void				two_dim_del(char ***array)
{
	char			**buff;

	buff = *array;
	while (*buff)
	{
		ft_strdel(&(*buff));
		buff++;
	}
	free(*array);
	*array = NULL;
}

size_t				content_len(t_list *list, char *content)
{
	size_t			len;

	len = 0;
	while (list && ft_strstr((char *)list->content, content))
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_vertex			*allocate_vertex(size_t size)
{
	t_vertex		*vert_arr;

	if (!(vert_arr = (t_vertex *)ft_memalloc(sizeof(t_vertex) * size)))
		print_error(BAD_ALLOC);
	return (vert_arr);
}
