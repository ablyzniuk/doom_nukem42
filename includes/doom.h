/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:16:46 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 13:16:48 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

#include <SDL.h>
#include <math.h>
#include <unistd.h>
#include "libft.h"

#define RAY_BETWEEN_ANGLE 60.0 / (double)WIDTH

#define WIDTH 900
#define HEIGHT 600
#define	HALFWIDTH (double)WIDTH / 2.0
#define	FOV 60
#define	FPS 60
#define	TICKS_FRAME 333 / FPS
#define	VECX 1
#define	VECY 0
#define DIST (double)WIDTH * 1.3	// рассчет дальности плоскости проекци. для фова 60
#define	ANG 180

typedef	struct	s_angle
{
	double		hor;
	double		ver;
}				t_angle;

typedef struct s_vertex
{
	double		x;
	double		y;
	double		z;
}				t_vertex;

typedef	struct	s_sendray
{
	int		num_sect;
	double	angle;
}				t_sendray;


typedef struct	s_ray
{
	double		angle; // угол каста луча
	double		vx;		// вектор каста луча
	double		vy;
	double		x;	// кординаты второй точки луча
	double		y;	
	double		ancos;	//пре кос син
	double		ansin;
	double		addlen;
	int			num_sect;	// номер стены
	int			wall_sect;
	int			len_ray;	
	int			w;
	double		camdist;	//фикс
	t_vertex	intersec;	// результат чека пересения
	t_vertex	ray;		//  кординаты второй точки луча
	t_vertex	bspray;	// кординаты первой точки после портала
	t_vertex	raystart;
}				t_ray;

typedef struct	s_fps
{
	double		time;
	double		oldtime;
	double		frametime;
	double		looktime;
	double		lookoldtime;
}				t_fps;

typedef	struct	s_sdl
{
	SDL_Window	*window;
	SDL_Surface *winsurface;
	SDL_Surface	*texture;
	SDL_Event	event;

}				t_sdl;

typedef struct	s_trplayer
{
	t_angle		angle;	// угол повота по осям
	t_vertex	pos;	// позиция игрока
	t_vertex	vec;	// вектор направления игрока
	int			sector;	// номер сектора где находиться ирок
	int			p_he;
	float		movespeed;	//скорость
	float		rotspeed;
	int			ecvator;

}               t_trpalyer;

typedef	struct	s_collision 
{
	t_vertex	raypos;
}				t_collision;


typedef	struct	s_event
{
	int		move_up;
	int		move_down;
	int		rot_rigth;
	int		rot_left;
	int		rot_up;
	int		rot_down;
	int		strafe_left;
	int		strafe_rigth;
	int		shoot_event;
	int		jump_event;
}				t_event;

typedef	struct	s_heigth
{
	int		min_he;
	int		max_he;
	double	z;
}				t_heigth;


typedef	struct	s_sector
{
	int			num_vert;	//количество точек
	int			numsector;	// номер сектора
	t_heigth	heigth;
	int			*vertex;	// массив точек сектора
	int			*typewall;
}				t_sector;

typedef	struct	s_intersection
{
	t_vertex	dir1;
	t_vertex	dir2;
	double		a1;
	double		b1;
	double		d1;
	double		a2;
	double		b2;
	double		d2;
	double		seg_line1_s;
	double		seg_line1_e;
	double		seg_line2_s;
	double		seg_line2_e;
	double		u;
}				t_intersection;

typedef	struct	s_main
{
	t_vertex	*vertex; // массив структур ввсех точек карты
	t_sector	**sector; // массив структур всех секторов
	int			sum_sect;	// количество секторов
	t_ray		ray;	// немного переменных 
	t_fps		fps;	// фпс
	t_sdl		sdl;	// все сдл переменные
	t_trpalyer	player;	// данные о игроке
	t_event		eventcall; // обработчик движений и т.д.

}				t_main;

void			ft_sdlinit(t_main *m);
void			ft_sdlloop(t_main *m);
void			ft_init(t_main *m);
void			ft_key(t_main *m, int *run);
void			ft_mouse(t_main *m);
void			ft_transform(t_main	*m);
void			ft_put_pixel(t_main *m, int x, int y, int pixel);
void			ft_fps_utils(t_main *m);
void			ft_fps_look(t_main *m);
void			ft_draw_map(t_main *m);
void			drawline(t_main *m, int x1, int y1, int x2, int y2);
t_vertex		ft_intersection(t_vertex st1, t_vertex end1, t_vertex st2, t_vertex end2);
void			drawscreen(t_main *m, int x, double z, int y0, int sect);
void			ft_load_texture(t_main *m);
void			ft_ray(t_main *m, t_ray ray);
int				ft_collision(t_main *m, t_vertex start, t_vertex end);

#endif