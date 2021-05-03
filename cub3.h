/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:43 by heom              #+#    #+#             */
/*   Updated: 2021/05/03 15:54:41 by heom             ###   ########.fr       */
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

//parsing_info
int     parsingInfo(char *line, t_info *parse_info);
int     parse_r(char *line, t_info *parse_info);
int     parse_news(char *line, t_info *parse_info, int start);
int     parse_rgb(char *line, t_info *parse_info, int start);
int     dupCheck(char *line, t_info *parse_info);


#endif