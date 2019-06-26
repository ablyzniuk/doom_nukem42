/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:39:15 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 15:02:45 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# define WIN_W		1280
# define WIN_H		720

# define NUM_TEX_T	10
# define NUM_TEX_P	16
# define NUM_TEX_A	11
# define NUM_TEX_O	3

# define WALL		0
# define CEIL		1
# define FLOOR		2
# define TEX		3

# define SETT_PAD	20

# include "libft.h"
# include <SDL.h>
# include <math.h>
# include <fcntl.h>

typedef enum		e_sett
{
	vertex,
	object,
	bind,
	portal,
	player,
	bad_big,
	editer,
	textures,
	cceil,
	ffloor
}					t_sett;

typedef struct		s_vertex
{
	int				x;
	int				y;
	int				z;
	int				number;
	struct s_vertex	*next;
}					t_vertex;

typedef struct		s_point
{
	t_vertex		position;
	int				current_sect;
	int				is_directional;
	int				health;
	struct s_point	*next;
}					t_point;

typedef struct		s_sect
{
	t_vertex		*vertex;
	int				vertex_count;
	int				number;
	int				is_child;

	int				hceil;
	int				hfloor;

	int				*is_portal;
	int				texture[3];
	struct s_sect	*next;
}					t_sect;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*surface;
	SDL_Event		event;
	int				transparent;
}					t_sdl;

typedef struct		s_edit
{
	t_sett			sett;

	t_vertex		*vertex;
	t_sect			*sect;
	t_sdl			*sdl;

	t_point			player;
	t_point			*enemy;
	t_point			*objects;
	int				health;
	int				ammo;

	t_sect			*ass_tex;
	int				index;

	t_vertex		*to_edit;

	t_sect			*portal_in_sect;
	t_vertex		*portal_start;
	t_vertex		*portal_end;

	t_vertex		bind_points[2];
	t_sect			*in_which;
	t_vertex		*ab;
	t_vertex		*cd;

	SDL_Surface		*icon;
	SDL_Surface		*(text)[2];
	SDL_Surface		*(obj)[NUM_TEX_O];
	SDL_Surface		*(bmp)[NUM_TEX_P];
	SDL_Surface		*(bmp_a)[NUM_TEX_A];
	int				pos_start[NUM_TEX_P][2];
	int				pos_end[NUM_TEX_P][2];
	int				x_bounds;
	int				y_tex;

	int				sect_is_closed;
	int				update;
	int				zoom;
}					t_edit;

typedef	struct		s_intersect
{
	int				o1;
	int				o2;
	int				o3;
	int				o4;
}					t_intersect;

typedef	struct		s_line
{
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;
	int				error2;
}					t_line;

typedef	struct		s_img
{
	int				x_init;
	int				x_start;
	int				y_start;
	int				move;
	int				flag;
}					t_img;

void				load_text(t_edit *edit);
void				load_img_pass(t_edit *edit);
void				load_img_active(t_edit *edit);
void				load_img_obj(t_edit *edit);
void				set_poss(t_edit **edit);

void				update(t_edit **edit);

void				sect_record(t_edit **edit, int x, int y);
t_sect				*new_sect(void);
t_sect				*get_last_sect(t_edit **edit);
t_sect				*get_sect_num(t_edit **edit, int num);
int					count_vertex(t_vertex *pvertex);
t_vertex			*new_vertex(int x, int y);
void				add_vertex(t_vertex **vertex, t_vertex *to_add,
							int counting);
t_vertex			*is_present(t_vertex *vertex, int x, int y);
int					cmp_vertex(t_vertex *first, t_vertex *last);
void				draw_bmp(t_sdl *sdl, SDL_Surface *bmp,
							int window_y, int window_x);
void				set_grid(t_edit *edit);
void				background_render(t_edit *edit);

void				icons_render(t_edit *edit, SDL_Surface **bmp, t_sdl *sdl);
void				data_render(t_edit *edit);
void				draw_line(t_sdl *sdl, t_vertex start,
							t_vertex end, int color);
void				pixel_put(t_sdl *sdl, int x, int y, int color);

void				declare_portal(t_edit **edit, int x, int y);
void				is_in_radius(t_edit **edit, int radius, int x, int y);
int					inter(t_vertex v1, t_vertex v2, t_vertex p1, t_vertex p2);

void				save(t_edit **edit, t_sect *s, t_vertex *p1, t_vertex *p2);
int					check(t_edit **edit, t_vertex *vertex, t_sect *sect);
void				clear_binder(t_edit **edit);
int					if_close(t_sect *sect, t_vertex *portal_start,
							t_vertex *portal_end);
void				bind_portals(t_edit **edit, int x, int y);

void				edit_vertex(t_edit **edit, int x, int y);

void				pick_texture(t_edit **edit, int x, int y);

void				edit_ceil_floor(t_edit **edit, int x, int y);

void				set_player(t_edit **edit, int x, int y);
void				set_enemy(t_edit **edit, int x, int y);
void				set_obj(t_edit **edit, int x, int y);
int					is_inside_sect(t_edit *edit, t_vertex point);

void				write_map(t_edit *edit, int fd);
void				write_vertex(t_sect *sect, t_vertex *all_vertex, int fd);
void				sort_vertex(t_vertex **p_vertex);

void				clear_binder(t_edit **edit);
void				terminate(char *str, t_sdl *sdl);

#endif
