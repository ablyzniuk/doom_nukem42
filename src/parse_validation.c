/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:50:09 by ablizniu          #+#    #+#             */
/*   Updated: 2019/05/10 14:38:39 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			tmp_list(t_list **lst, const void *content,
		const size_t content_size)
{
	t_list	*tmp;

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


size_t			two_dim_len(char **array)
{
	size_t size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void			two_dim_del(char ***array)
{
	char **buff;

	buff = *array;
	while (*buff)
	{
		ft_strdel(&(*buff));
		buff++;
	}
	free(*array);
	*array = NULL;
}

size_t content_len(t_list *list, char *content)
{
	size_t len;

	len = 0;
	while (list && ft_strstr((char *)list->content, content))
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_vertex 		*allocate_vertex(size_t size)
{
	t_vertex *vert_arr;

	if (!(vert_arr = (t_vertex *)ft_memalloc(sizeof(t_vertex) * size)))
		print_error(BAD_ALLOC);
	return (vert_arr);
}

double			*allocate_vertex_x_array(size_t size)
{
	double *array;

	if (!(array = (double *)ft_memalloc(sizeof(double) * size)))
		print_error(BAD_ALLOC);
	return (array);
}

double			parse_vertex_y(char *vertex_line)
{
	char	*s1;
	double	num;

	s1 = ft_strchr(vertex_line, DELIMITER) + 1;
	num = ft_atof(s1);
	return (num);
}

char			*find_x_values(char *vertex_line)
{
	char		*tmp;

	tmp = vertex_line;
	while (ft_strchr(tmp, DELIMITER))
		tmp = ft_strchr(tmp, DELIMITER) + 1;
	return (tmp);
}

double			*parse_vertex_x(char *vertex_line, size_t *size_arr)
{
	char		**tmp;
	double		*array;
	size_t 		size;
	size_t		iterator;

	iterator = 0;
	tmp = ft_strsplit(find_x_values(vertex_line), ' ');
	size = two_dim_len(tmp);
	array = allocate_vertex_x_array(size);
	while (iterator < size)
	{
		array[iterator] = ft_atof(tmp[iterator]);
		iterator++;
	}
	*size_arr = size;
	two_dim_del(&tmp);
	return (array);
}

t_bool		validate_dilims(char *vertex_data)
{
	char	*tmp;
	size_t	num;

	num = 0;
	tmp = vertex_data;
	while (ft_strchr(tmp, DELIMITER))
	{
		tmp = ft_strchr(tmp, DELIMITER) + 1;
		num++;
	}
	if (num < 2 || num > 2)
		return (false);
	return (true);
}

t_bool		validate_num(char *vertex_data)
{
	t_bool	res;
	size_t	size;
	char	*buff;

	size = 0;
	while (ft_isdigit(vertex_data[size]))
		size++;
	buff = ft_strndup(vertex_data, size);
	res = ft_isint(buff, false);
	ft_strdel(&buff);
	return (res);
}

t_bool		validate_coords(char *vertex_data)
{
	size_t	index;
	size_t	num;

	num = 0;
	index = 0;
	while (vertex_data[index])
	{
		if (vertex_data[index] != DELIMITER && vertex_data[index] != ' ')
		{
			if (!ft_isdigit(vertex_data[index]) || !validate_num(&vertex_data[index]))
				return (false);
			else
			{
				num++;
				while (vertex_data[index] && (ft_isdigit(vertex_data[index]) || vertex_data[index] == '.'))
					index++;
				continue ;
			}
		}
		index++;
	}
	if (num < 2)
		return (false);
	return (true);
}

t_bool		validate_vertex(char *vertex_data)
{
	char	*data;
	size_t	vertex_len;

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

void		parse_vertex(t_main *main, t_list *list)
{
	size_t	vertex_num;
	size_t	iterator;
	size_t	size_arr;
	t_list	*elem;

	iterator = 0;
	size_arr = 0;
	elem = find_elem(list, "vertex");
	vertex_num = content_len(elem, "vertex");
	main->vertex = allocate_vertex(vertex_num);
	while (elem && iterator < vertex_num)
	{
		if (validate_vertex((char *)elem->content))
		{
			main->vertex[iterator].y = parse_vertex_y((char *)elem->content);
			main->vertex[iterator].x_arr = parse_vertex_x((char *)elem->content, &size_arr);
			main->vertex[iterator].x_arr_size = size_arr;
			main->sum_vert_pair += size_arr;
			elem = elem->next;
			iterator++;
		}
		else
			print_error(BAD_VERTEX_VALIDATION);
	}
	main->sum_vert = vertex_num;
}

void		read_file(t_main *main)
{
	char	*line;
	int32_t	fd;
	t_list	*list;

	list = NULL;
	if (!(fd = open("resourse/map.txt", O_RDONLY)))
		print_error(BAD_FILE);
	while (get_next_line(fd, &line))
	{
		tmp_list(&list, (void *)line, ft_strlen(line));
		ft_strdel(&line);
	}
	parse_vertex(main, list);
	parse_sector(main, list);
	parse_player(main, list);
}
