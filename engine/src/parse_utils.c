/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:06:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:25 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double			*allocate_vertex_pair(void)
{
	double		*vertex;

	if (!(vertex = (double *)ft_memalloc(sizeof(double) * 2)))
		print_error(BAD_ALLOC);
	return (vertex);
}

int32_t			*allocate_transition_array(size_t size)
{
	int32_t		*transition;

	if (!(transition = (int32_t *)ft_memalloc(sizeof(int32_t) * size)))
		print_error(BAD_ALLOC);
	return (transition);
}

double			*search_vertex_pair(t_main *main, int32_t pair)
{
	double		*vertex_pair;
	size_t		i;
	size_t		j;

	i = 0;
	vertex_pair = allocate_vertex_pair();
	while (i < main->sum_vert)
	{
		j = 0;
		while (j < main->vertex[i].x_arr_size)
		{
			if (pair == 0)
			{
				vertex_pair[0] = main->vertex[i].y;
				vertex_pair[1] = main->vertex[i].x_arr[j];
				return (vertex_pair);
			}
			pair--;
			j++;
		}
		i++;
	}
	return (NULL);
}

t_bool			integer_overload_error(char **data)
{
	while (*data)
	{
		if (!ft_isint(*data, false) && !ft_strchr(*data, '.'))
			print_error(BAD_VALIDATION_INT32_OVERLOAD);
		data++;
	}
	return (false);
}

t_heigth		parse_heigth_params(char *data)
{
	t_heigth	heigth;
	char		**tmp;

	ft_bzero(&heigth, sizeof(t_heigth));
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_dim_len(tmp) == 2 && !integer_overload_error(tmp))
		{
			heigth.floor = ft_atof(tmp[INDEX(1)]);
			heigth.cell = ft_atof(tmp[INDEX(2)]);
		}
		else
			print_error(BAD_SECTOR_VALIDATION_HEIGHT);
		two_dim_del(&tmp);
	}
	return (heigth);
}
