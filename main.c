/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 16:23:30 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int			main(int argc, char **argv)
{
	int		res;
	char	**map;
	t_info	parse_info;
	t_list	*map_list;

	if (argc == 2)
	{
		res = 0;
		ft_bzero(&parse_info, sizeof(t_info));
		parse_info.dup[8] = '\0';
		parse_info.pos[0] = -1;
		map_list = NULL;
		if (!(res = parsing_all(&parse_info, map_list, &map, argv[1])))
		{
			printf("error\n Invalid value in map pile");
			return (0);
		}
		if (res == 0)
			printf("error\n parsing_info duple err\n");
		res = mlx_process(&parse_info, map);
		split_free(map);
	}
	else if (argc == 3)
	{
		//save position
		return (0);
	}
		return (0);
}