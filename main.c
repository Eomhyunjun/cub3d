/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 19:52:13 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int			main(int argc, char **argv)
{
	int		res;
	char	**map;
	t_info	parse_info;
	t_list	*map_list;

	if (!(argc <= 3 && argc >= 2 && !ft_strncmpr(argv[1], ".cub", 4)))
		return (print_err("map name is invalid."));
	if (argc >= 2)
	{
		res = 0;
		ft_bzero(&parse_info, sizeof(t_info));
		parse_info.dup[8] = '\0';
		parse_info.pos[0] = -1;
		map_list = NULL;
		if (!(res = parsing_all(&parse_info, map_list, &map, argv[1])))
			return (print_err("Invalid value in map file"));
		res = mlx_process(&parse_info, map, argc);
		split_free(map);
	}
	print_err("Do it with a set format.");
	return (0);
}
