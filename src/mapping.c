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
t_rgb		ft_get_pixel_ceil(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
	double	dx, dy, dist, diff, dd;
	double	xx, yy, distc, wq, rx, ry, k;
	t_vertex	kk;
	t_rgb		rgb;

//	xx = (m->sector[ray.num_sect].heigth.floor - );

	wall.y = (fabs(wall.dx) > fabs(wall.dy) ? (int)((ray.intersec.x - ray.wall_start.x) * 1000) :
							(int)((ray.intersec.y - ray.wall_start.y) * 1000)) % m->texture[0]->w;


	wq = (1.0) / (ray.camdist);
	dx = (ray.intersec.x - m->player.pos.x);
	dy = (ray.intersec.y - m->player.pos.y);
	diff_y = dy / ray.camdist;
	diff_x = dx / ray.camdist;
	xx = fabs(m->player.pos.x + (x * diff_x));
	yy = fabs(m->player.pos.y + (x * diff_y));
	dd = sqrt(pow(m->player.pos.x - xx, 2) + pow(m->player.pos.y - yy, 2));
	// wq = (50.0 * DIST) / fabs(dd);
	//printf("%f %f \n", xx, dd);
	// k = (float)(wall.floor - wall.ceil) * (float)(1.0 - wall.floor);
	// wq = ray.camdist / k;
	// rx = 1000.0;
	// xx = (int)(wq * rx + (1.0f - wq) * m->player.pos.x);
	// yy = (int)(wq * rx + (1.0f - wq) * m->player.pos.y);


//	printf("%f %f \n", xx, yy);


	GET_COLOR(color, m->texture[3]->pixels, (int)(wall.y * 100) % m->texture[3]->w,
	m->texture[3]->pitch, (int)(wall.y * 100) % m->texture[3]->h, m->texture[3]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[3]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}
t_rgb		ft_get_pixel_floor(t_main *m, t_ray ray, t_heigth_wall wall, double x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
	double	dx, dy, dist, diff, dd;
	double	xx, yy, distc, wq, rx, ry, k;
	t_vertex	kk;
	t_rgb		rgb;

//	xx = (m->sector[ray.num_sect].heigth.floor - );

	dx = fabs(ray.intersec.x - m->player.pos.x);
	dy = fabs(ray.intersec.y - m->player.pos.y);


//	printf("%f %f %f", dy, dx, ray.camdist);
	diff_y = dy / (ray.camdist - ray.addlen);
	diff_x = dx / (ray.camdist - ray.addlen);


	xx = fabs((x * diff_x));
	yy = fabs((x * diff_y));
	// yy = ((dx) > (dy) ? ((ray.intersec.x - ray.wall_start.x) * 100) :
	// 						((ray.intersec.y - ray.wall_start.y) * 100));
       
	dx = (xx - ray.intersec.x);
	dy = (yy - ray.intersec.y);


	dd = fabs(sqrt(pow(dx, 2) + pow(dy, 2)));


	xx = fabs(dd * ray.vx);
	yy = fabs(dd * ray.vy);

	//printf("%f %f \n", xx, dd);
	// k = (float)(wall.floor - wall.ceil) * (float)(1.0 - wall.floor);
	// wq = ray.camdist / k;
	// rx = 1000.0;
//	printf("%f %f \n", xx, yy);


	GET_COLOR(color, m->texture[3]->pixels, (int)(xx * 100.0) % m->texture[3]->w,
	m->texture[3]->pitch, (int)(yy * 100.0) % m->texture[3]->h, m->texture[3]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[3]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb		ft_get_pixel_wall(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	static int32_t	buff = -1;
	static int32_t	col = 0xffffff;
	int32_t	i;
	double	diff_x;
	t_rgb 	rgb;

	//ray.camdist = ray.camdist;
	diff_x = 64.0 / (double)wall.wall_h_map;

	//i = (int)((x * diff_x) * 100) % m->texture[0]->h;
	SET_I(i, x, diff_x, m->texture[0]->h);
	rgb.b = (col << 16);
	rgb.g = (col << 8);
	rgb.r = (col);
	if (i != buff)
	{
	//	color = m->texture[0]->pixels + i * m->texture[0]->pitch +
	//	y * m->texture[0]->format->BytesPerPixel;
		GET_COLOR(color, m->texture[0]->pixels, i, m->texture[0]->pitch, y, m->texture[0]->format->BytesPerPixel);
		SDL_GetRGB(*color, m->texture[0]->format, &rgb.r, &rgb.g, &rgb.b);
		col = *color;
	}
	buff = i;
	return (rgb);
}

t_rgb		ft_get_pixel_border(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
	t_rgb 	rgb;

	ray.camdist = ray.camdist;
	diff_y = wall.border_b_h / (wall.diff_bord_bot > 0 ? wall.diff_bord_bot : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((x * diff_x) * 64) % m->texture[1]->w;
	//color = m->texture[1]->pixels + i * m->texture[1]->pitch +
	//y * m->texture[1]->format->Byt esPerPixel;
	GET_COLOR(color, m->texture[1]->pixels, i, m->texture[1]->pitch, y, m->texture[1]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[1]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}

t_rgb		ft_get_pixel_border_top(t_main *m, t_ray ray, t_heigth_wall wall, int32_t x, int32_t y)
{
	int32_t	*color;
	int32_t	i;
	double	diff_x, diff_y;
	t_rgb 	rgb;
	
	ray.camdist = ray.camdist;
	diff_y = wall.border_t_h / (wall.diff_bord_top > 0 ? wall.diff_bord_top : 1) * 4;
	diff_x = 10 / diff_y;
	i = (int)((x * diff_x) * 64) % m->texture[1]->w;
	//color = m->texture[1]->pixels + i * m->texture[1]->pitch +
	//y * m->texture[1]->format->BytesPerPixel;
	GET_COLOR(color, m->texture[1]->pixels, i, m->texture[1]->pitch, y, m->texture[1]->format->BytesPerPixel);
	SDL_GetRGB(*color, m->texture[1]->format, &rgb.r, &rgb.g, &rgb.b);
	return (rgb);
}