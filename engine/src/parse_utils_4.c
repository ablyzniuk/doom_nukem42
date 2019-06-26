/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:36 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:18:37 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

inline t_sector	processing(t_main *main, size_t index, char *sector_data)
{
	t_sector	sector;
	char		**data_array;

	ft_bzero(&sector, sizeof(t_sector));
	if (sector_data)
	{
		data_array = ft_strsplit(ft_strchr(sector_data, DELIMITER), DELIMITER);
		if (two_dim_len(data_array) == 4)
		{
			sector.color = 0;
			sector.sector_index = index;
			sector.heigth = parse_heigth_params(data_array[INDEX(1)]);
			sector.vertex = parse_vertex_params(data_array[INDEX(2)], main,
					&sector.vertex_arr_len);
			sector.transit = parse_transit_parameters(data_array[INDEX(3)],
					sector.vertex_arr_len);
			sector.textures = parse_textures(data_array[INDEX(4)]);
		}
		else
			print_error(BAD_SECTOR_VALIDATION_NUM);
		two_dim_del(&data_array);
	}
	return (sector);
}

void			parse_sector(t_main *main, t_list *list)
{
	t_list		*elem;
	size_t		len;
	size_t		i;

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

t_vertex		define_player_pos(char *data)
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

t_trpalyer		parse_player_parameters(char *data)
{
	char		**tmp;
	t_trpalyer	player;

	ft_bzero(&player, sizeof(t_trpalyer));
	if (data)
	{
		tmp = ft_strsplit(ft_strchr(data, DELIMITER), DELIMITER);
		if (two_dim_len(tmp) == 2)
		{
			player.pos = define_player_pos(tmp[INDEX(1)]);
			if (!integer_overload_error(&tmp[INDEX(2)]))
				player.sector = ft_atoi(tmp[INDEX(2)]);
		}
		else
			print_error(BAD_PLAYER_VALIDATION_SECTOR_POS);
		two_dim_del(&tmp);
	}
	return (player);
}

void			parse_player(t_main *main, t_list *list)
{
	t_list		*elem;

	elem = find_elem(list, "player");
	main->player = parse_player_parameters((char *)elem->content);
}
