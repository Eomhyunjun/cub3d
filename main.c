#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "src/get_next_line.h"
#include "libft/libft.h"

typedef struct s_info
{
    char *rw;
    char *rh;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *s;
    char *f;
    char *c;
} t_info;

int     parse_R(char *line, t_info *parse_info)
{
    char    **bottle;
    char    *start;
    
    start = line;
    line += 2;
    while (*line == ' ')
        line++;
    
    if (!ft_isdigit(*line))
        return (0); //parsing err

    while (*line)
    {
        if (ft_isdigit(*line))
            line++;
        else if (*line == ' ')
            break ;
        else
            return (0); //parsing err
    }
    while (*line == ' ')
        line++;
    while (*line)
    {
        if (ft_isdigit(*line))
            line++;
        else if (*line == '\0')
            break;
        else
            return (0); //parsing err
    }

    bottle = ft_split(start, ' '); // need free
    parse_info->rw = bottle[1];
    parse_info->rh = bottle[2];
    return (1);
}


int    parse_news(char *line, t_info *parse_info, int start)
{
    int i;

    i = 0;
    while (line[i++])
    ;
    while (line[start] == ' ')
        start++;
    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        parse_info->no = ft_strndup(line, start, i); //dup
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        parse_info->so = ft_strndup(line, start, i);
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        parse_info->we = ft_strndup(line, start, i);
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        parse_info->ea = ft_strndup(line, start, i);
    else if (line[0] == 'S' && line[1] == ' ')
        parse_info->s = ft_strndup(line, start, i);
    return (1);
}

int    parse_rgb(char *line, t_info *parse_info, int start)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (line[start] == ' ')
        start++;
    i = start;
    while (ft_isdigit(line[i]) || line[i] == ',')
    {
        if (ft_isdigit(line[i]))
            i++;
        else if((line[i] == ',' && ft_isdigit(line[i+1]) == 1) && j <= 1)
        {
            i++;
            j++;
        }
        else 
            return (0); /* ',' num over err or Out of specification  */
    }
    if (line[0] == 'F' && line[1] == ' ')
        parse_info->f = ft_strndup(line, start, i); // need free
    else if (line[0] == 'C' && line[1] == ' ')
        parse_info->c = ft_strndup(line, start, i); // need free
    return (1);
}

int     parse_map(char *line, char **map)
{
    if(!(*map = ft_strdup(line)))  // need free
    {
        return (0);
    }
    
    return (1);
}

int     devide(char *line, t_info *parse_info, char **map)
{
    int res;

    res = 0;
    if (line[0] == '\0')
        res = 1;
    if (line[0] == 'R' && line[1] == ' ')
        res = parse_R(line, parse_info);
    else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'S' && line[1] == ' ')
        res = parse_news(line, parse_info, 2);
    else if (line[0] == 'F' && line[1] == ' ')
        res = parse_rgb(line, parse_info, 2);
    else if (line[0] == 'C' && line[1] == ' ')
        res = parse_rgb(line, parse_info, 2);
    else if (ft_isdigit(line[0])) // 엘스 받아서 띄어쓰기 공백 처리하기
        res = parse_map(line, map);
    return (res);
}

int get_next_line_arg(int fd, char **line, int *res)
{
    *res = get_next_line(fd, line);
    return (*res);
}

int parsingAll(void)
{
    t_info parse_info;
    char    *map[24];
    char    *parse;
    char    *line;
    int     fd;
    int     i;
    int     res;

    i = 0;
    ft_bzero(&parse_info, sizeof(t_info));
    fd = open("map.cub", O_RDWR);
    while (get_next_line_arg(fd, &line, &res))
    {            
        if (!devide(line, &parse_info, &map[i]))
            return (0); /* parsing err */ 
        i++;
    }
    printf(" Rw : %s\n Rh : %s\n NO : %s\n SO : %s\n WE : %s\n EA : %s\n S : %s\n F : %s\n C : %s\n", parse_info.rw, parse_info.rh, parse_info.no, parse_info.so,parse_info.we,parse_info.ea,parse_info.s,parse_info.f,parse_info.c);
    for (i = 9; *map[i] != '\0'; i++)
        printf("%s\n", map[i]);
    if (res == 1)
        return (1); /* eof */
    return (0); /* get_next_line err */
}

int     main(void)
{
    int res;

    res = 0;
    res = parsingAll();
    return (0);
}