/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:38 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:18:40 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double			**parse_vertex_pair(t_main *main, char **data, size_t size)
{
	double		**vertex_array;
	int32_t		val;
	size_t		i;

	i = 0;
	vertex_array = allocate_vertex_array(size);
	while (i < size)
	{
		val = ft_atoi(data[i]);
		if (FT_ABS(val) < main->sum_vert_pair)
			vertex_array[i] = search_vertex_pair(main, val);
		else
			print_error(BAD_SECTOR_VALIDATION_BAD_VERTEX_PAIR);
		i++;
	}
	return (vertex_array);
}

double			**parse_vertex_params(char *data, t_main *main, size_t *len)
{
	double		**vertex_array;
	char		**tmp;

	vertex_array = NULL;
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_dim_len(tmp) >= 3 && !integer_overload_error(tmp))
		{
			*len = two_dim_len(tmp);
			vertex_array = parse_vertex_pair(main, tmp, *len);
		}
		else
			print_error(BAD_SECTOR_VALIDATION_VERTEX);
		two_dim_del(&tmp);
	}
	return (vertex_array);
}

int32_t			*parse_transit_pair(char **data, size_t size)
{
	int32_t		*trans;
	size_t		i;

	i = 0;
	trans = allocate_transition_array(size);
	while (i < size)
	{
		trans[i] = ft_atoi(data[i]);
		i++;
	}
	return (trans);
}

int32_t			*parse_transit_parameters(char *data, size_t vertex_array_len)
{
	int32_t		*trans;
	char		**tmp;

	trans = NULL;
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_dim_len(tmp) == vertex_array_len &&
				!integer_overload_error(tmp))
			trans = parse_transit_pair(tmp, vertex_array_len);
		else
			print_error(BAD_SECTOR_VALIDATION_TRANSIT);
		two_dim_del(&tmp);
	}
	return (trans);
}

t_textures		parse_textures(char *data)
{
	t_textures	textures;
	char		**tmp;

	ft_bzero(&textures, sizeof(t_textures));
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_dim_len(tmp) == 3 && !integer_overload_error(tmp))
		{
			textures.wall = ft_atoi(tmp[INDEX(1)]);
			textures.floor = ft_atoi(tmp[INDEX(2)]);
			textures.celling = ft_atoi(tmp[INDEX(3)]);
		}
		else
			print_error(BAD_VALIDATION);
		two_dim_del(&tmp);
	}
	return (textures);
}
