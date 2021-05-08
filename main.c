/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/07 15:59:19 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

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
    if(!(res = parsing_all(&parse_info, map_list, &map)))
	{ // map에 값 잘못 넣으면 NULL 값 리턴되게 했는데 세그먼트 뜸;;
		printf("ERRRRRRRRRRRRR\n");
		return (0);
	}
    printf("====================================================\n");
	int i = 0;
    while (map[i])
    {
        printf("|%s|\n", map[i]);
        i++;
    }
    printf("====================================================\n");
    if (res == 0)           //print remove
        printf("hello duple err");
    mlx_process(parse_info, map);
    return (0);
}