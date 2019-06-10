/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:13:34 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/30 14:13:37 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_get_pixel(SDL_Surface *texture, int32_t x, int32_t y)
{
	int32_t	*get_pixel;

	get_pixel = texture->pixels + y * texture->pitch +
	x * texture->format->BytesPerPixel;
	return (*get_pixel);
}

int32_t		ft_get_pixel_wall(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	color = 0;
	int32_t	i, j;
	int32_t	k;
	double	diff_x, diff_y;

	diff_y = wall.wall_h_map;
	diff_x = 65.0 / diff_y;
	i = (int)((x * diff_x) * 100.0) % 1000;

	color = ft_get_pixel(m->texture, y, i);
	return (color);
}