/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:42 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/26 16:17:52 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_bool				validate_vertex(char *vertex_data)
{
	char			*data;
	size_t			vertex_len;

	vertex_len = ft_strlen("vertex");
	if (!ft_strequ(vertex_data, "vertex"))
	{
		data = vertex_data + vertex_len;
		if (!validate_dilims(data) || !validate_coords(data))
			print_error(BAD_VERTEX_VALIDATION);
	}
	else
		print_error(BAD_VERTEX);
	return (true);
}

void				fill_vertex(t_main *main, char *content, size_t iterator)
{
	size_t			size_arr;

	size_arr = 0;
	main->vertex[iterator].y = parse_vertex_y(content);
	main->vertex[iterator].x_arr =
			parse_vertex_x(content, &size_arr);
	main->vertex[iterator].x_arr_size = size_arr;
	main->sum_vert_pair += size_arr;
}

void				parse_vertex(t_main *main, t_list *list)
{
	size_t			vertex_num;
	size_t			iterator;
	t_list			*elem;

	iterator = 0;
	elem = find_elem(list, "vertex");
	if (elem)
	{
		vertex_num = content_len(elem, "vertex");
		main->vertex = allocate_vertex(vertex_num);
		while (elem && iterator < vertex_num)
		{
			if (validate_vertex((char *)elem->content))
				fill_vertex(main, (char *)elem->content, iterator);
			else
				print_error(BAD_VERTEX_VALIDATION);
			elem = elem->next;
			iterator++;
		}
		main->sum_vert = vertex_num;
	}
	else
		print_error(BAD_VERTEX_VALIDATION);
}

static void			free_tmp_list(t_list **head)
{
	t_list			*tmp;

	while (*head)
	{
		tmp = *head;
		ft_memdel(&tmp->content);
		ft_memdel((void *)&tmp);
		(*head) = (*head)->next;
	}
	ft_memdel((void **)head);
}

void				read_file(t_main *main, char *str)
{
	char			*line;
	int32_t			fd;
	t_list			*list;
	char			*path;

	list = NULL;
	path = ft_strjoin("resources/en/maps/", str);
	if (0 >= (fd = open(path, O_RDONLY)))
		print_error(BAD_FILE);
	while (get_next_line(fd, &line) > 0)
	{
		tmp_list(&list, (void *)line, ft_strlen(line));
		ft_strdel(&line);
	}
	parse_vertex(main, list);
	parse_sector(main, list);
	parse_player(main, list);
	parse_enemy(main, list);
	parse_decor(main, list);
	free_tmp_list(&list);
}
