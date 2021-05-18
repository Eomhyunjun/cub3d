/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:42 by heom              #+#    #+#             */
/*   Updated: 2021/05/18 14:28:11 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

// static int	compare(const void *first, const void *second)
// {
// 	if (*(int *)first > *(int *)second)
// 		return (1);
// 	else if (*(int *)first < *(int *)second)
// 		return (-1);
// 	else
// 		return (0);
// }

// void	sort_order(t_pair *orders, int amount)
// {
// 	t_pair	tmp;

// 	for (int i = 0; i < amount; i++)
// 	{
// 		for (int j = 0; j < amount - 1; j++)
// 		{
// 			if (orders[j].first > orders[j + 1].first)
// 			{
// 				tmp.first = orders[j].first;
// 				tmp.second = orders[j].second;
// 				orders[j].first = orders[j + 1].first;
// 				orders[j].second = orders[j + 1].second;
// 				orders[j + 1].first = tmp.first;
// 				orders[j + 1].second = tmp.second;
// 			}
// 		}
// 	}
// }

// void	sortSprites(int *order, double *dist, int amount)
// {
// 	t_pair	*sprites;

// 	//std::vector<std::pair<double, int>> sprites(amount);
// 	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
// 	for (int i = 0; i < amount; i++)
// 	{
// 		sprites[i].first = dist[i];
// 		sprites[i].second = order[i];
// 	}
// 	sort_order(sprites, amount);
// 	//std::sort(sprites.begin(), sprites.end());
// 	for (int i = 0; i < amount; i++)
// 	{
// 		dist[i] = sprites[amount - i - 1].first;
// 		order[i] = sprites[amount - i - 1].second;
// 	}
// 	free(sprites);
// }

void	calc(t_all *all)
{
	int x;
	t_calc cal;
	// t_list sprite_list;

	x = 0;
	// sprite_list->content = 0;
	// sprite_list->next = 0;
	//printf("width : %d height : %d\nposx : %f, posy : %f \n dirx : %f, diry : %f\nplanex : %f, planey : %f\n\n", all->width, all->height, all->posx, all->posy, all->dirx, all->diry, all->planex, all->planey);
	while (x < all->width)
	{
		calc_init(all, &cal, x);
		set_step_side(all, &cal);
		set_hit(all, &cal);
		set_draw_point(all, &cal);
		set_tex_point(all, &cal);
		put_back_buf(all, x);
		put_wall_buf(all, &cal, x);
		x++;
	}
}