/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:06:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/05/10 15:54:51 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_list *find_elem(t_list *list, char *elem)
{
	while (!ft_strstr((char *)list->content, elem))
		list = list->next;
	return (list);
}

t_sector	*allocate_sector(size_t size)
{
	t_sector *sector;

	if (!(sector = (t_sector *)ft_memalloc(sizeof(t_sector) * size)))
		print_error(BAD_ALLOC);
	return (sector);
}

double		**allocate_vertex_array(size_t size)
{
	double **array;

	if (!(array = (double **)ft_memalloc(sizeof(double *) * size + 1)))
		print_error(BAD_ALLOC);
	return (array);
}

double		*allocate_vertex_pair()
{
	double	*vertex;

	if (!(vertex = (double *)ft_memalloc(sizeof(double) * 2)))
		print_error(BAD_ALLOC);
	return (vertex);
}

int32_t			*allocate_transition_array(size_t size)
{
	int32_t	*transition;

	if (!(transition = (int32_t *)ft_memalloc(sizeof(int32_t) * size)))
		print_error(BAD_ALLOC);
	return (transition);
}

double			*search_vertex_pair(t_main *main, int32_t pair)
{
	double *vertex_pair;
	size_t	i;
	size_t	j;

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

void		show_the_fuck(double **arr, size_t size)// для проверки, я тупо писал, с первого раза все норм пашет, и ликов нету
{
	size_t i = 0;
	size_t j = 0;

	while (i < size)
	{
		j = 0;
		printf("[");
		while (j < 2)
		{
			printf("%f ", arr[i][j]);
			j++;
		}
		printf("]");
		printf("\n");
		i++;
	}
	printf("\n");
}
/*------------------------------------------------------------*/

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

double		**parse_vertex_pair(t_main *main, char **data, size_t size)
{
	double	**vertex_array;
	int32_t	val;
	size_t	i;

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
//	show_the_fuck(vertex_array, size);//для проверки записанных вертексных пар
	return (vertex_array);
}

double		**parse_vertex_params(char *data, t_main *main, size_t *len)
{
	double	**vertex_array;
	char	**tmp;

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
	size_t i;

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
		if (two_dim_len(tmp) == vertex_array_len && !integer_overload_error(tmp))
			trans = parse_transit_pair(tmp, vertex_array_len);
		else
			print_error(BAD_SECTOR_VALIDATION_TRANSIT);
		two_dim_del(&tmp);
	}
	return (trans);
}

inline t_sector processing(t_main *main, size_t index, char *sector_data)
{
	t_sector	sector;
	char		**data_array;

	ft_bzero(&sector, sizeof(t_sector));
	if (sector_data)
	{
		data_array = ft_strsplit(ft_strchr(sector_data, DELIMITER), DELIMITER);
		if (two_dim_len(data_array) == 3)
		{
			sector.color = 0;
			sector.sector_index = index;
			sector.heigth = parse_heigth_params(data_array[INDEX(1)]);
			sector.vertex = parse_vertex_params(data_array[INDEX(2)], main, &sector.vertex_arr_len);
			sector.transit = parse_transit_parameters(data_array[INDEX(3)], sector.vertex_arr_len);
			two_dim_del(&data_array);
		}
		else
			print_error(BAD_SECTOR_VALIDATION_NUM);
	}
	return (sector);
}

void		parse_sector(t_main *main, t_list *list)
{
	t_list	*elem;
	size_t	len;
	size_t	i;

	i = 0;
	elem = find_elem(list, "sector");
	len = content_len(elem, "sector");
	main->sector = allocate_sector(len);
	while (elem && i < len)
	{
		main->sector[i] = processing(main, i, (char *)elem->content);
		elem = elem->next;
		i++;
	}
	main->sum_sect = len;
}

t_vertex	define_pos(char *data)
{
	t_vertex	pos;
	char		**tmp;

	ft_bzero(&pos, sizeof(t_vertex));
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_dim_len(tmp) == 3 && !integer_overload_error(tmp))
		{
			pos.x = ft_atof(tmp[INDEX(1)]);
			pos.y = ft_atof(tmp[INDEX(2)]);
			pos.z = ft_atof(tmp[INDEX(3)]);
		}
		else
			print_error(BAD_PLAYER_VALIDATION);
		two_dim_del(&tmp);
	}
	return (pos);
}

t_trpalyer	parse_player_parameters(char *data)
{
	char		**tmp;
	t_trpalyer	player;

	ft_bzero(&player, sizeof(t_trpalyer));
	if (data)
	{
		tmp = ft_strsplit(ft_strchr(data, DELIMITER), DELIMITER);
		if (two_dim_len(tmp) == 2)
		{
			player.pos = define_pos(tmp[INDEX(1)]);
			if (!integer_overload_error(&tmp[INDEX(2)]))
				player.sector = ft_atoi(tmp[INDEX(2)]);
		}
		else
			print_error(BAD_PLAYER_VALIDATION_SECTOR_POS);
		two_dim_del(&tmp);
	}
	return (player);
}

void	parse_player(t_main *main, t_list *list)
{
	t_list *elem;

	elem = find_elem(list, "player");
	main->player = parse_player_parameters((char *)elem->content);
}
