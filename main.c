#include <unistd.h>
#include <fcntl.h>
#include "mygnl/get_next_line.h"

typedef struct s_info
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *s;
    char *Rw;
    char *Rh;
    char *Frgb;
    char *Crgb;
} t_info

int     parse_R(char *line, t_info *parse_info)
{
    char bottle[4];

    bottle[3] = '\0';
    line++;
    while(is_blank(*line))
        line++;
    if (is_space(*line))
        line++;
    else
        return (0); //parsing err

    whlie(*line)
    {
        if (is_digit(*line))
            line++;
        else if (*line == ' ')
            break;
        else
            return (0) //parsing err
    }

    whlie(*line)
    {
        if (ft_is_digit(*line))
            line++;
        else if (*line == '\0')
            break;
        else
            return (0) //parsing err
    }

    bottle = ft_split(line, ' ');
    parse_info.Rw = bottle[1];
    parse_info.Rh = bottle[2];
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
    if (line[0] == 'N' && line[1] == 'O', && line[2] == ' ')
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
    while (ft_isnum(line[i]) || line[i] == ',')
    {
        if (ft_isnum(line[i]))
            i++;
        if else (line[i] == ',' && ft_isnum(line[i+1] == 1) && j <= 1)
        {
            i++;
            j++;
        }
        else 
            return (0); /* ',' num over err or Out of specification  */
    }
    if (line[0] == 'F' && line[1] == ' ')
        parse_info->f = ft_strndup(line, start, i);
    else if (line[0] == 'C' && line[1] == ' ')
        parse_info->c = ft_strndup(line, start, i);
    return (1);
}

int     devide(char *line)
{
    t_info parse_info;
    int res;

    res = 0;
    bzero(parse_info);
    if (line[0] == 'R' && line[1] == ' ')
        res = parse_R(line, &parse_info);
    else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        res = parse_news(line, &parse_info, 3);
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        res = parse_news(line, &parse_info, 3);
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        res = parse_news(line, &parse_info, 3);
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        res = parse_news(line, &parse_info, 3);
    else if (line[0] == 'S' && line[1] == ' ')
        res = parse_news(line, &parse_info, 2);
    else if (line[0] == 'F' && line[1] == ' ')
        res = parse_rgb(line, &parse_info, 2);
    else if (line[0] == 'C' && line[1] == ' ')
        res = parse_rgb(line, &parse_info, 2);
    return (res)
}

int     parsingAll(void)
{
    char    *parse;
    char    *line;
    int     fd;
    int     res;

    fd = open("map.cub", O_RDWR);
    while (res = get_next_line(fd, &line))
    {            
        if (!devide(line))
            return (0); /* parsing err */ 
    }
    if (res == 1)
        return (1); /* eof */
    return (0); /* get_next_line err */
}

int     main(void)
{
    int res;

    res = 0;
    res = parsingAll();
    ft_printf("")
    return (0);
}