/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:43 by heom              #+#    #+#             */
/*   Updated: 2021/05/07 16:00:21 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "src/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17 //Exit program key code

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC			53

typedef struct s_info
{
    char    *rw;
    char    *rh;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *s;
    char    *f;
    char    *c;
    int     dup[9];
    int     longlen;
    int     cols;
} t_info;

typedef struct	s_img {
	void		*img;
	int	        *data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;


typedef struct	s_player
{
	int			x;
	int			y;
	int			color;
}				t_player;

typedef struct	s_mini
{
	void	*mlx;
	void	*win;
	t_img	img;
    t_player player;

	char 	**map;
    int     width;
    int     height;
    int     cols;
    int     rows;

    int     grid_color;
}				t_mini;

//arg
int     get_next_line_arg(int fd, char **line, int *res);
int     parsing_all(t_info  *parse_info, t_list  *map_list, char ***map);

//parsing_info
int     parsing_info(char *line, t_info *parse_info);
int     parse_r(char *line, t_info *parse_info);
int     parse_news(char *line, t_info *parse_info, int start);
int     parse_rgb(char *line, t_info *parse_info, int start);
int     dup_check(char *line, t_info *parse_info);

//parsing_map
int     parsing_map(char *line, t_list **map_list, t_info *parse_info);
char    *put_space(int longlen);
int     copy_map(t_list *map_list, char **map, int longlen);
char    **make_matrix(t_list *map_list, char **map, int longlen);
int	    exam_map(char **map, int x, int y);
int     map_errchk(char **map);
char    **check_map(t_list *map_list, t_info *parse_info);

//mlx_fuc

int     mlx_process(t_info parse_info, char **map);
void	win_img_init(t_mini *mini);

int		draw_mini_map(t_mini *mini);
void	draw_wall(t_mini *mini, int y, int x);

void	init_player(t_mini *mini);
void	move_dot_left(t_mini *mini);
void	move_dot_right(t_mini *mini);
void	move_dot_up(t_mini *mini);
void	move_dot_down(t_mini *mini);
int		press_key_for_dot(int key, t_mini *mini);

#endif