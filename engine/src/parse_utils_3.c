/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:18:32 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/23 15:18:34 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_vertex		define_universal_pos(char *data)
{
	t_vertex	pos;
	char		**tmp;

	ft_bzero(&pos, sizeof(t_vertex));
	if (data)
	{
		tmp = ft_strsplit(data, ' ');
		if (two_dim_len(tmp) == 2 && !integer_overload_error(tmp))
		{
			pos.x = ft_atof(tmp[INDEX(1)]);
			pos.y = ft_atof(tmp[INDEX(2)]);
		}
		else
			print_error(BAD_VALIDATION);
		two_dim_del(&tmp);
	}
	return (pos);
}

t_decor			parse_decor_parameters(char *data)
{
	t_decor		decor;
	char		**tmp;

	ft_bzero(&decor, sizeof(t_decor));
	if (*data)
	{
		tmp = ft_strsplit(ft_strchr(data, DELIMITER), DELIMITER);
		if (two_dim_len(tmp) == 2)
		{
			decor.pos = define_universal_pos(tmp[INDEX(1)]);
			if (!integer_overload_error(&tmp[INDEX(2)]))
				decor.sector = ft_atoi(tmp[INDEX(2)]);
		}
		else
			print_error(BAD_VALIDATION_SECTOR_POS);
		two_dim_del(&tmp);
	}
	return (decor);
}

t_enemy			parse_enemy_parameters(char *data)
{
	t_enemy		enemy;
	char		**tmp;

	ft_bzero(&enemy, sizeof(t_enemy));
	if (*data)
	{
		tmp = ft_strsplit(ft_strchr(data, DELIMITER), DELIMITER);
		if (two_dim_len(tmp) == 2)
		{
			enemy.pos = define_universal_pos(tmp[INDEX(1)]);
			if (!integer_overload_error(&tmp[INDEX(2)]))
				enemy.sector = ft_atoi(tmp[INDEX(2)]);
		}
		else
			print_error(BAD_VALIDATION_SECTOR_POS);
		two_dim_del(&tmp);
	}
	return (enemy);
}

void			parse_enemy(t_main *main, t_list *list)
{
	size_t		i;
	t_list		*elem;
	size_t		enemy_num;

	i = 0;
	elem = find_elem(list, "enemy");
	enemy_num = content_len(elem, "enemy");
	main->enemies = allocate_enemy(enemy_num);
	while (elem && i < enemy_num)
	{
		main->enemies[i] = parse_enemy_parameters((char *)elem->content);
		main->enemies[i].health *= main->difficulty;
		elem = elem->next;
		i++;
	}
}

void			parse_decor(t_main *main, t_list *list)
{
	size_t		i;
	t_list		*elem;
	size_t		decor_num;

	i = 0;
	elem = find_elem(list, "decor");
	decor_num = content_len(elem, "decor");
	main->decor = allocate_decor(decor_num);
	while (elem && i < decor_num)
	{
		main->decor[i] = parse_decor_parameters((char *)elem->content);
		elem = elem->next;
		i++;
	}
}
