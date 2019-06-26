/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:15 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:17 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double				*allocate_vertex_x_array(size_t size)
{
	double			*array;

	if (!(array = (double *)ft_memalloc(sizeof(double) * size)))
		print_error(BAD_ALLOC);
	return (array);
}

double				parse_vertex_y(char *vertex_line)
{
	char			*s1;
	double			num;

	s1 = ft_strchr(vertex_line, DELIMITER) + 1;
	num = ft_atof(s1);
	return (num);
}

char				*find_x_values(char *vertex_line)
{
	char			*tmp;

	tmp = vertex_line;
	while (ft_strchr(tmp, DELIMITER))
		tmp = ft_strchr(tmp, DELIMITER) + 1;
	return (tmp);
}

double				*parse_vertex_x(char *vertex_line, size_t *size_arr)
{
	char			**tmp;
	double			*array;
	size_t			size;
	size_t			iterator;

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

t_bool				validate_dilims(char *vertex_data)
{
	char			*tmp;
	size_t			num;

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
