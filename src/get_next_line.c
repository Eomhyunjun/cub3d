/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:36 by heom              #+#    #+#             */
/*   Updated: 2021/02/26 03:06:35 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **backup, char *sp)
{
	char *line;
	char *temp;

	if (!*backup)
		return (ft_strdup(""));
	if (sp == NULL)
	{
		if (!(sp = ft_strchr(*backup, '\n')))
		{
			line = *backup;
			*backup = NULL;
			return (line);
		}
	}
	*sp = '\0';
	if (!(line = ft_strdup(*backup)))
		return (NULL);
	if (!(temp = ft_strdup(sp + 1)))
		return (NULL);
	free(*backup);
	*backup = temp;
	return (line);
}

char	*get_backup(char *backup, char *buf)
{
	char *temp;

	if (backup == NULL)
	{
		backup = ft_strdup(buf);
	}
	else
	{
		temp = backup;
		backup = ft_strjoin(backup, buf);
		free(temp);
	}
	return (backup);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	ssize_t		read_size;
	char		*sp;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE <= 0) || (fd > OPEN_MAX))
		return (-1);
	sp = NULL;
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!(backup[fd] = get_backup(backup[fd], buf)))
			return (-1);
		if ((sp = ft_strchr(backup[fd], '\n')))
			break ;
	}
	if (read_size == -1)
		return (-1);
	if (!(*line = get_line(&backup[fd], sp)))
		return (-1);
	return (backup[fd] ? 1 : 0);
}
