/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:16:46 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/27 13:13:42 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include "errors.h"
# include <math.h>
# include <unistd.h>
# include "libft.h"
# include <time.h>

# define FIELD_OF_VIEW	66
# define WIDTH			1080
# define HEIGHT			700
# define HALFWIDTH		(double)WIDTH / 2.0
# define HALFHEIGTH		HEIGHT / 2
# define VFOV			.2f
# define FPS			60
# define TICKS_FRAME	333 / FPS
# define VECX			(double)1
# define VECY			(double)0
# define DIST			(double)WIDTH * 1.3
# define ANG			180
# define COLS			5
# define FOG			60
# define SET_FOG(x, y, z, a) (x = y - (double)y / a * z * FOG)
# define GET_COLOR(c, p, i, pi, y, b) (c = p + i * pi + y * b)
# define SET_I(i, x, d, h) (i = (int)(x * d * 50.0) % h)
# define DELIMITER		'\t'
# define PADD			20

typedef	struct		s_valid
{
	unsigned char	data;
	struct s_valid	*next;
}					t_valid;

typedef	struct		s_angle
{
	double			hor;
	double			ver;
}					t_angle;

typedef struct		s_rgb
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_rgb;

typedef struct		s_vertex
{
	double			x;
	double			y;
	double			z;
	double			*x_arr;
	size_t			x_arr_size;
}					t_vertex;

typedef	struct		s_sendray
{
	int32_t			num_sect;
	double			angle;
}					t_sendray;

typedef	struct		s_height_w
{
	int32_t			flag;
	int32_t			start;
	int32_t			end;
	int32_t			floor_h;
	int32_t			ceil_h;
}					t_height_w;

typedef	struct		s_spr_tex
{
	SDL_Surface		*ch;
	int32_t			num_spr;
}					t_spr_tex;

typedef	struct		s_colll
{
	int32_t			tp;
	double			dist;
	double			move;
}					t_colll;

typedef	struct		s_spr
{
	size_t			spr_num;
	Uint8			is_enemy;
	t_vertex		pos;
	size_t			sect;
	Uint8			hp;

}					t_spr;

typedef	struct		s_spr_data
{
	double			w[WIDTH];
	double			dist[WIDTH];
	double			angle[WIDTH];
	double			vecx;
	double			vecy;
	double			anglee;
	t_vertex		pos;

}					t_spr_data;

typedef	struct		s_buffer
{
	int32_t			buffer_draw_bot;
	int32_t			buffer_draw_top;

}					t_buffer;

typedef struct		s_heigth_wall
{
	t_height_w		border_top;
	t_height_w		border_bot;
	t_height_w		floor_h;
	t_height_w		ceil_h;
	int32_t			w;
	int32_t			y;
	double			dx;
	double			dy;
	int32_t			start;
	int32_t			end;
	int32_t			color;
	double			floor;
	double			ceil;
	double			he_wall;
	int32_t			old_end;
	int32_t			old_start;
	int32_t			wall_h_map;
	int32_t			diff_bord_bot;
	int32_t			diff_bord_top;
	int32_t			border_t_h;
	int32_t			border_b_h;
	int32_t			old_border_t_h;
	int32_t			old_border_b_h;
	int32_t			cell_h_map;
	int32_t			floor_h_map;
	double			diff;
	double			he_sect;
}					t_heigth_wall;

typedef	struct		s_draw_save
{
	int32_t			old_w;
	int32_t			buffer_bot;
	int32_t			buffer_top;
}					t_draw_save;

typedef struct		s_ray
{
	double			angle;
	double			total_angle;
	double			vx;
	double			vy;
	double			ancos;
	double			ansin;
	double			addlen;
	double			wall_len;
	double			wall_len_ray;
	int32_t			next_sect;
	int32_t			camdist_old;
	int32_t			old_num_sect;
	int32_t			num_sect;
	size_t			wall_sect;
	int32_t			len_ray;
	int32_t			wall_type;
	int32_t			w;
	size_t			ray_deep;
	double			camdist;
	t_vertex		intersec;
	t_vertex		ray_end;
	t_vertex		ray_start;
	t_vertex		wall_start;
	t_vertex		wall_end;
}					t_ray;

typedef	struct		s_save_ray
{
	t_vertex		sv_ray_end;
	t_vertex		sv_pos;
	int32_t			sv_sect;
	int32_t			sv_old_sect;

}					t_save_ray;

typedef struct		s_fps
{
	double			time;
	double			oldtime;
	double			frametime;
	double			looktime;
	double			lookoldtime;
}					t_fps;

typedef	struct		s_sdl
{
	SDL_Surface		*debug;
	TTF_Font		*font;
	SDL_Window		*window;
	SDL_Surface		*winsurface;
	SDL_Surface		*skybox;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_trplayer
{
	t_angle			angle;
	t_vertex		pos;
	t_vertex		vec;
	int32_t			sector;
	double			p_he;
	float			movespeed;
	float			jump_h;
	float			rotspeed;
	int32_t			ecvator;

	int				ammo;
	int				hp;
}					t_trpalyer;

typedef	struct		s_event
{
	int32_t			move_up;
	int32_t			move_down;
	int32_t			rot_rigth;
	int32_t			rot_left;
	int32_t			rot_up;
	int32_t			rot_down;
	int32_t			strafe_left;
	int32_t			strafe_rigth;
	int32_t			shoot_event;
	int32_t			jump_event;
	int32_t			flag_debug;
	int32_t			geg_flag;
	int32_t			is_ground;
	int32_t			look_jump;
	int32_t			eee;
}					t_event;

typedef	struct		s_heigth
{
	double			floor;
	double			cell;
}					t_heigth;

typedef struct		s_sky
{
	t_vertex		start;
	t_vertex		end;
	int32_t			h;
	int32_t			w;
	SDL_Surface		*sky;
}					t_sky;

typedef	struct		s_collision
{
	t_vertex		vec_x;
	t_vertex		vec_y;
	t_vertex		result;
	double			wall_len;
	double			len_start;
	double			len_end;
	int32_t			flag_x;
	int32_t			flag_y;
	size_t			wall_sect;

}					t_collision;

typedef	struct		s_cols_wall
{
	t_vertex			start;
	t_vertex			end;
	int32_t				type;
	int32_t				num_wall;
	int32_t				sector;
	struct s_cols_wall	*next;
}					t_cols_wall;

typedef	struct		s_textures
{
	int8_t			floor;
	int8_t			celling;
	int8_t			wall;
}					t_textures;

typedef	struct		s_sector
{
	size_t			color;
	size_t			sector_index;
	double			**vertex;
	size_t			vertex_arr_len;
	t_textures		textures;
	t_heigth		heigth;
	t_spr			*spr;
	t_cols_wall		*cols;
	int32_t			*transit;
}					t_sector;

typedef	struct		s_intersection
{
	t_vertex		dir1;
	t_vertex		dir2;
	double			a1;
	double			b1;
	double			d1;
	double			a2;
	double			b2;
	double			d2;
	double			seg_line1_s;
	double			seg_line1_e;
	double			seg_line2_s;
	double			seg_line2_e;
	double			u;
}					t_intersection;

typedef	struct		s_debug
{
	int32_t			top_start;
	int32_t			top_end;
	int32_t			wall;
}					t_debug;

typedef	struct		s_enemy
{
	t_vertex		pos;
	int8_t			health;
	int32_t			sector;
}					t_enemy;

typedef	struct		s_decor
{
	t_vertex		pos;
	int32_t			sector;
}					t_decor;

typedef struct		s_setting
{
	uint8_t	fog;
}					t_setting;

typedef struct		s_pict
{
	SDL_Surface		*end[2];
	SDL_Surface		*start;
	SDL_Surface		*(butt)[4];
	int				sstart[4][2];
	int				eend[4][2];
}					t_pict;

typedef struct		s_anim
{
	SDL_Surface		*bullet;
	SDL_Surface		*(r)[40];
	SDL_Surface		*(s)[3];
	int				curr;
}					t_anim;

typedef struct		s_music
{
	Mix_Music		*audio;
	Mix_Chunk		*gunshot;
	int8_t			chanel;
	t_bool			switcher;
}					t_music;

typedef struct		s_iter
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				k;
	double			dx;
	double			dy;
	double			dist;
	double			dist2;
	float			ancos;
	float			ansin;
	int				start;
	int				len;
	int				w;
	int				sv;
}					t_iter;

typedef struct		s_line
{
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;
	int				error2;
}					t_line;


typedef	struct		s_main
{
	clock_t			time;
	t_rgb			col;
	int8_t			difficulty;
	t_anim			anim;
	double			zhora_run;
	t_vertex		*vertex;
	t_sector		*sector;
	t_vertex		pos;
	t_pict			pict;
	t_music			music;
	size_t			sum_sect;
	size_t			sum_vert;
	size_t			sum_vert_pair;
	t_collision		cols;
	t_setting		setting;
	t_ray			ray;
	t_sky			sky;
	t_fps			fps;
	t_sdl			sdl;
	t_spr_data		spr_data;
	t_debug			debug;
	t_spr_tex		sprite;
	t_trpalyer		player;
	t_enemy			*enemies;
	t_decor			*decor;
	t_event			eventcall;
	SDL_Surface		*texture[7];
}					t_main;

void final_scene(t_main *main);

void				decreaze_hp(t_main *main);

void				fill_vertex(t_main *main, char *content, size_t iterator);

double				ft_get_dist_cols(t_cols_wall *lst,
						t_collision cols, t_vertex pos_vec);

void				ft_coll2(t_main *m, t_vertex pos_vec, t_colll *coco,
					t_cols_wall *lst);

void				ft_coll1(t_main *m, t_vertex pos_vec, t_colll *coco,
					t_cols_wall *lst);

void				ft_move_add(t_main *m, t_vertex *pos,
					t_vertex pos_vec, t_colll coco);

void				ft_coll1(t_main *m, t_vertex pos_vec, t_colll *coco,
					t_cols_wall *lst);

void				ft_draw_border_border_bot_start(t_main *m, t_ray ray,
					t_heigth_wall *wall, t_buffer *buf);

void				ft_draw_border_border_top_start(t_main *m, t_ray ray,
					t_heigth_wall *wall, t_buffer *buf);

void				ft_drawscreen_0(int32_t *border_b_h, int32_t *border_t_h, t_heigth_wall wall);
t_draw_save			ft_drawscreen_1(t_main *m, t_ray ray,  t_heigth_wall *wall, t_buffer *buffer);
t_vertex			*allocate_vertex(size_t size);
double				ft_get_len_wall(t_vertex start, t_vertex end);
void				ft_draw_map(t_main *m);
void				ft_get_array_wall(t_main *m, t_ray *ray);
void				ft_get_data_ray(t_main *m, t_ray *ray);
void				read_file(t_main *main, char *str);
void				parse_vertex(t_main *main, t_list *list);
t_bool				validate_vertex(char *vertex_data);
t_bool				validate_num(char *vertex_data);
t_bool				validate_coords(char *vertex_data);
double				*allocate_vertex_x_array(size_t size);
double				parse_vertex_y(char *vertex_line);
char				*find_x_values(char *vertex_line);
double				*parse_vertex_x(char *vertex_line, size_t *size_arr);
t_bool				validate_dilims(char *vertex_data);
void				tmp_list(t_list **lst, const void *content,
							const size_t content_size);
double				is_higher(t_heigth_wall wall);
int					ft_get_pixel(SDL_Surface *texture, int32_t x, int32_t y);
void				ft_get_border_bot(t_main *m, t_ray ray, t_heigth_wall *wall);
void				ft_get_floor(t_main *m, t_ray ray, t_heigth_wall *wall);
void				ft_get_border_top(t_main *m, t_ray ray, t_heigth_wall *wall);
void				ft_get_ceil(t_main *m, t_ray ray,
							t_heigth_wall *wall, t_buffer *buf);
void				ft_put_pixel(t_main *m, int x, int y, int32_t pixel);
void				ft_put_pixel_rgb(t_main *m, int x, int y, t_rgb col);
void				drawline(t_main *m, t_vertex s, t_vertex e);
void				ft_get_wall_heigth(t_main *m, t_ray ray, t_heigth_wall *wall);
void				ft_key_exit(t_main *m, int *run);
double_t			get_dist_ceil(void);
t_bool				integer_overload_error(char **data);
double				*search_vertex_pair(t_main *main, int32_t pair);
int32_t				*allocate_transition_array(size_t size);
double				*allocate_vertex_pair(void);
void				ft_geg(t_main *m);
void				ft_transform_jump(t_main *m);
void				ft_transform_strafe(t_main *m);
void				ft_transform_pos(t_main *m);
t_heigth			parse_heigth_params(char *data);
double				**parse_vertex_pair(t_main *main, char **data, size_t size);
double				**parse_vertex_params(char *data, t_main *main, size_t *len);
int32_t				*parse_transit_pair(char **data, size_t size);
int32_t				*parse_transit_parameters(char *data, size_t vertex_array_len);
t_textures			parse_textures(char *data);
t_sector			processing(t_main *main, size_t index, char *sector_data);
void				parse_sector(t_main *main, t_list *list);
t_vertex			define_player_pos(char *data);
t_trpalyer			parse_player_parameters(char *data);
void				parse_player(t_main *main, t_list *list);
t_vertex			define_universal_pos(char *data);
t_decor				parse_decor_parameters(char *data);
t_enemy				parse_enemy_parameters(char *data);
void				parse_enemy(t_main *main, t_list *list);
void				parse_decor(t_main *main, t_list *list);
t_list				*find_elem(t_list *list, char *elem);
t_sector			*allocate_sector(size_t size);
t_decor				*allocate_decor(size_t size);
t_enemy				*allocate_enemy(size_t size);
double				**allocate_vertex_array(size_t size);
void				gui_buttondown(t_main *main, SDL_Event event);
void				bullet_manage(t_main *m);
void				draw_gun(t_main *m);
void				draw_bmp(t_main *m, SDL_Surface *bmp, int win_y, int win_x);
void				ft_load_reload_1(t_main *m, int i);
void				ft_load_reload_2(t_main *m, int i);
void				ft_load_shoot(t_main *m, int i);
t_rgb				ft_get_pixel_ceil(t_main *m, t_ray ray, t_heigth_wall wall);
void				ft_load_music(t_main *m);
void				ft_sprite(t_main *m);
double_t			get_dist(void);
void				parse_decor(t_main *main, t_list *list);
void				parse_enemy(t_main *main, t_list *list);
void				parse_player(t_main *main, t_list *list);
t_list				*find_elem(t_list *list, char *elem);
t_sector			processing(t_main *main, size_t index, char *sector_data);
size_t				content_len(t_list *list, char *content);
void				parse_sector(t_main *main, t_list *list);
t_main				*init_main(void);
void				print_error(const char *msg);
void				two_dim_del(char ***array);
size_t				two_dim_len(char **array);
void				init_buttons(t_main *main);
void				start_menu(t_main *main);
void				ft_sdlinit(t_main *m);
void				ft_sdlloop(t_main *m);
void				ft_init(t_main *m, char *way);
void				ft_key(t_main *m, int32_t *run);
void				ft_mouse(t_main *m);
void				ft_transform(t_main	*m);
void				ft_put_pixel(t_main *m, int32_t x,
							int32_t y, int32_t pixel);
void				ft_put_pixel_rgb(t_main *m, int32_t x,
							int32_t y, t_rgb pixel);
int					ft_get_pixel(SDL_Surface *texture, int32_t x, int32_t y);
void				ft_fps_utils(t_main *m);
void				ft_draw_map(t_main *m);
t_vertex			ft_intersection(t_vertex st1, t_vertex end1,
							t_vertex st2, t_vertex end2);
void				ft_drawscreen(t_main *m, t_ray ray);
void				ft_draw_floor(t_main *m, t_ray ray,
							t_heigth_wall wall, t_buffer *buf);
t_rgb
ft_get_pixel_wall(t_main *m, t_heigth_wall wall, t_ray ray, int32_t *data_arr);
t_rgb ft_get_pixel_border(t_main *m, t_heigth_wall wall, int32_t *iter_arr, t_ray ray);
t_rgb ft_get_pixel_border_top(t_main *m, t_heigth_wall wall, int32_t *iter_arr, t_ray ray);
t_rgb				ft_get_pixel_floor(t_main *m, t_ray ray,
							t_heigth_wall wall);
void				ft_draw_wall(t_main *m, t_ray ray,
							t_heigth_wall wall, t_buffer *buf);
void				ft_draw_cell(t_main *m, t_ray ray,
							t_heigth_wall wall, t_buffer *buf);
void				ft_draw_border(t_main *m, t_ray ray,
							t_heigth_wall wall, t_buffer *buf);
void				ft_load_texture(t_main *m);
double				ft_dist_cord(double x1, double y1, double x2, double y2);
void				ft_ray(t_main *m, t_ray ray);
int32_t				ft_collision(t_main *m, t_vertex pos_vec, double move);
t_rgb				ft_set_fog(t_rgb rgb, t_ray ray);
void				ft_gravity(t_main *m);
void				ft_de_gravity(t_main *m);
void				ft_lst_add_back(t_cols_wall *start, t_cols_wall *lst);
void				ft_init_sky(t_main *m);
void				ft_sprite(t_main *m);
void				ft_draw_sky(t_main *m);
void				ft_cr_cols_init(t_main *m);
t_cols_wall			*ft_cr_new_list(void);

#endif
