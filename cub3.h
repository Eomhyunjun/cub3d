/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:16:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 20:25:55 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "utils/gnl/get_next_line.h"
# include "utils/libft/libft.h"
# include "mlx/mlx.h"
# include "get_screen/mlx_custom.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT	17
# define K_ESC			53
# define K_Q			12
# define K_W			13
# define K_E			14
# define K_R			15
# define K_A			0
# define K_S			1
# define K_D			2
# define K_LF			123
# define K_RT			124

# define TEXWIDHT 64
# define TEXHEIGHT 64

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		distx;
	double		disty;
	double		coefx;
	double		coefy;
	double		centerx;
	double		depth_unit;
	double		real_depth;
	double		size;
	double		drawstart;
	double		drawend;
	double		tex_scale;
	double		tex_step;
}				t_sprite;

typedef struct	s_info
{
	int			rw;
	int			rh;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f;
	int			c;
	int			dup[9];
	int			longlen;
	int			cols;
	char		dir;
	int			pos[2];
	int			spr_num;
}				t_info;

typedef struct	s_img {
	void		*img;
	int			*data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_img		img;

	int			width;
	int			height;
	char		**map;

	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;

	int			k_w;
	int			k_s;
	int			k_a;
	int			k_d;
	int			k_lf;
	int			k_rt;
	int			texture[7][TEXHEIGHT * TEXWIDHT];
	double		movespeed;
	double		rotspeed;

	int			spr_num;
	int			spr_cnt;
	double		*zbuf;
}				t_all;

typedef struct	s_calc
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			texnum;
	int			lineheight;
	int			drawstart;
	int			drawend;

	double		wallx;
	int			tex;
	int			texy;
	int			color;
	double		step;
	double		texpos;
}				t_calc;

/*
**--------------------- arg -------------------
*/

int				get_next_line_arg(int fd, char **line, int *res);
int				parsing_all(t_info *parse_info, t_list *map_list \
				, char ***map, char *argv);
void			split_free(char **bottle);
int				print_err(char *str);

/*
**--------------------- parsing_info -------------------
*/
int				info_check(int fd, char **line, t_info *parse_info);
int				parsing_info(char *line, t_info *parse_info);
int				parse_r(char *line, t_info *parse_info);
int				parse_news(char *line, t_info *parse_info, int start);
int				parse_rgb(char *line, t_info *parse_info, int start);
int				dup_check(char *line, t_info *parse_info);

/*
**--------------------- parsing_map -------------------
*/

void			parsing_map(char *line, t_list **map_list, t_info *parse_info);
char			*put_space(int longlen);
int				copy_map(t_list *map_list, char **map \
				, t_info *parse_info, int y);
char			**make_matrix(t_list *map_list, char **map, t_info *parse_info);
int				exam_map(char **map, int x, int y);
int				map_errchk(char **map);
char			**check_map(t_list *map_list, t_info *parse_info);
/*
**--------------------- make_color -------------------
*/
int				create_trgb(int t, int r, int g, int b);
int				color_len_chk(int r, int g, int b);
int				make_rgb(char *line, t_info *parse_info, int start, int i);
/*
**--------------------- graphics -------------------
*/
int				mlx_process(t_info *parse_info, char **map, int argc);
int				main_loop(t_all *all);
int				exit_loop(t_all *all);

void			all_init(t_all *all, t_info *parse_info);
void			put_wall_buf(t_all *all, t_calc *cal, int x);
void			put_back_buf(t_all *all, int x);
int				load_image(t_all *all, int *texture, char *path, t_img *img);
int				texture_init(t_all *all, t_info *parse_info);
int				make_texnum(int stepx, int stepy, int side);

void			calc(t_all *all);
void			calc_init(t_all *all, t_calc *cal, int x);
void			set_step_side(t_all *all, t_calc *cal);
void			set_hit(t_all *all, t_calc *cal, t_sprite *spr);
void			set_draw_point(t_all *all, t_calc *cal, int x);
void			set_tex_point(t_all *all, t_calc *cal);

void			key_update(t_all *all);
int				key_press(int key, t_all *all);
int				key_release(int key, t_all *all);

void			rotation_pro(t_info *parse_info, t_all *all);
void			rotation(t_all *all, int degree);

int				malloc_zbuf(t_all *all);
t_sprite		*sprite_init(t_all *all);
void			set_sprite(t_all *all, t_calc *cal, t_sprite *spr);
void			set_coef(t_all *all, t_sprite *spr);
void			sort_spr(t_all *all, t_sprite *spr);
int				is_x_here(t_all *all, t_calc *cal, t_sprite *spr);

/*
**--------------------------save--------------------
*/
int				save_bitmap(t_all *all);
int				make_bitmap_file(t_all *all);

#endif
