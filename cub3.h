/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:43 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 14:11:45 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "src/get_next_line/get_next_line.h"
# include "libft/libft.h"

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
} t_info;

//arg
int     get_next_line_arg(int fd, char **line, int *res);

//parsing_info
int     parsingInfo(char *line, t_info *parse_info);
int     parse_r(char *line, t_info *parse_info);
int     parse_news(char *line, t_info *parse_info, int start);
int     parse_rgb(char *line, t_info *parse_info, int start);
int     dupCheck(char *line, t_info *parse_info);

//parsing_map
int     parsingMap(char *line, t_list **map_list, t_info *parse_info);
char    *putSpace(int longlen);
int     copyMap(t_list *map_list, char **map);
char    **makeMatrix(t_list *map_list, char **map, int longlen);
int     mapErrCehck(char **map);
char    **checkMap(t_list *map_list, char **map, t_info *parse_info);


#endif