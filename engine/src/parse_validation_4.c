/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:39:18 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:39:19 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_bool				validate_num(char *vertex_data)
{
	t_bool			res;
	size_t			size;
	char			*buff;

	size = 0;
	while (ft_isdigit(vertex_data[size]))
		size++;
	buff = ft_strndup(vertex_data, size);
	res = ft_isint(buff, false);
	ft_strdel(&buff);
	return (res);
}

static t_bool		is_valid(size_t num)
{
	if (num < 2)
		return (false);
	return (true);
}

t_bool				validate_coords(char *vertex_data)
{
	size_t			index;
	size_t			num;

	num = 0;
	index = 0;
	while (vertex_data[index])
	{
		if (vertex_data[index] != DELIMITER && vertex_data[index] != ' ')
		{
			if (!ft_isdigit(vertex_data[index]) ||
					!validate_num(&vertex_data[index]))
				return (false);
			else
			{
				num++;
				while (vertex_data[index] && (ft_isdigit(vertex_data[index]) ||
						vertex_data[index] == '.'))
					index++;
				continue ;
			}
		}
		index++;
	}
	return (is_valid(num));
}
