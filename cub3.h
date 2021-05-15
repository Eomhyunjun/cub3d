/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:16:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/15 22:23:38 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "utils/get_next_line/get_next_line.h"
# include "utils/libft/libft.h"
# include "mlx/mlx.h"


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

#define texwidth 64
#define texheight 64

typedef struct  s_info
{
	char		*rw;
	char		*rh;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*f;
	char		*c;
	int			dup[9];
	int			longlen;
	int			cols;
	char		dir;
	int			pos[2];
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
	int			**buf;
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
	int			texture[7][texheight * texwidth];
	double		movespeed;
	double		rotspeed;
}				t_all;

typedef struct s_calc
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
	int 		stepx;
	int 		stepy;
	int 		hit;
	int 		side;
	int 		texnum;

}				t_calc;

/*
--------------------- arg -------------------
*/
int				get_next_line_arg(int fd, char **line, int *res);
int				parsing_all(t_info  *parse_info, t_list  *map_list, char ***map, char *argv);
void			split_free(char **bottle);


/*
--------------------- parsing_info -------------------
*/
int				parsing_info(char *line, t_info *parse_info);
int				parse_r(char *line, t_info *parse_info);
int				parse_news(char *line, t_info *parse_info, int start);
int				parse_rgb(char *line, t_info *parse_info, int start);
int				dup_check(char *line, t_info *parse_info);

/*
--------------------- parsing_map -------------------
*/
void			parsing_map(char *line, t_list **map_list, t_info *parse_info);
char			*put_space(int longlen);
int				copy_map(t_list *map_list, char **map, t_info *parse_info, int y);
char			**make_matrix(t_list *map_list, char **map, t_info *parse_info);
int				exam_map(char **map, int x, int y);
int				map_errchk(char **map);
char			**check_map(t_list *map_list, t_info *parse_info);

/*
--------------------- make_color -------------------
*/
int		create_trgb(char *trgb);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*
--------------------- graphics -------------------
*/
int		mlx_process(t_info *parse_info, char **map);
void	all_init(t_all *all, t_info *parse_info);
void	malloc_buf(t_all *all);
int		load_image(t_all *all, int *texture, char *path, t_img *img);
int		texture_init(t_all *all, t_info *parse_info);
int		make_texnum(t_all *all, int stepx, int stepy, int side);

int		main_loop(t_all *all);
void	calc(t_all *all);
void	draw(t_all *all);
void	key_update(t_all *all);
int		key_press(int key, t_all *all);
int		key_release(int key, t_all *all);

void	rotation_pro(t_info *parse_info, t_all *all);
void	rotation(t_all *all, int degree);
#endif