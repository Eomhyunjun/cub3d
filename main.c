/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/06 21:07:35 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"


int		main_loop(t_mini *mini)
{
	int	pos;
	int	i;

	i = 0;
	while (i <= mini->rows)
	{
		pos = 0;
		while (pos <= mini->width){
			mlx_pixel_put(mini->mlx, mini->win, pos, i * (mini->height / mini->rows),mini->grid_color);
			pos++;
		}
		i++;
	}
	i = 0;
	while (i <= mini->cols)
	{
		pos = 0;
		while (pos <= mini->width){
			mlx_pixel_put(mini->mlx, mini->win, i * (mini->width/ mini->cols), pos,mini->grid_color);
			pos++;
		}
		i++;
	}
	return (0);
}

void	win_img_init(t_mini *mini)
{

	mini->grid_color = 0xFFFFFF;
	mini->mlx = mlx_init();
	mini->win = mlx_new_window(mini->mlx, mini->width, mini->height, "HEOM's Cub3d Mini_Map"); // window 상자
    mini->img.img = mlx_new_image(mini->mlx, mini->width, mini->height); // image 상자
    mini->img.data = (int *)mlx_get_data_addr(mini->img.img, &mini->img.bits_per_pixel, &mini->img.line_length, &mini->img.endian); //image 정보 틀 제공
}

int     mlx_process(t_info parse_info, char **map)
{   
	void	*mlx;
	void	*win;
    t_mini  mini;
    
    mini.width = ft_atoi(parse_info.rw);
    mini.height = ft_atoi(parse_info.rh);
    mini.cols = parse_info.cols - 2;
    mini.rows = parse_info.longlen - 3;
    mini.map = map;
	win_img_init(&mini);

	//mini.img.img = mlx_xpm_file_to_image(mlx, "./doge.xpm", &mini.cols, &mini.rows);
    //mlx_put_image_to_window(mini.mlx, mini.win, mini.img.img, 0, 0);

    mlx_loop_hook(mini.mlx, &main_loop, &mini);
    mlx_loop(mini.mlx);
    
    return (0);
}

int     main(void)
{
    int     res;
    char    **map;
    t_info  parse_info;
    t_list  *map_list;

    res = 0;
    ft_bzero(&parse_info, sizeof(t_info));
    parse_info.dup[8] = '\0';
    map_list = NULL;
    res = parsing_all(&parse_info, map_list, map);
    
    if (res == 0)           //print remove
        printf("hello duple err");
    mlx_process(parse_info, map);
    return (0);
}