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

int		ft_get_pixel(SDL_Surface *texture, int x, int y)
{
	int	*get_pixel;

	get_pixel = texture->pixels + y * texture->pitch +
	x * texture->format->BytesPerPixel;
	return (*get_pixel);
}

int32_t		ft_get_pixel_wall(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	color = 0;
	double	diff;
	int32_t	i, j;

	diff = 10 / wall.he_sect;
	i = wall.start * diff;
	i = i % 64;
	j = ray.w % 64;
	color = ft_get_pixel(m->texture, j, i);
	return (color);
}