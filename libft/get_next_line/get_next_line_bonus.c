/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:18:17 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/12/28 23:01:03 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*set_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	i += 1 * (backup[i] == '\n');
	line = (char *)malloc((i + 1));
	if (!(line))
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*set_strnig(char *backup)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && (backup[i] != '\n'))
		i++;
	if (backup[i] == '\n')
		i++;
	if (!(backup[i]))
	{
		free(backup);
		return (0);
	}
	temp = (char *)malloc(ft_strlen(backup) - i + 1);
	if (!temp)
		return (0);
	j = 0;
	while (backup[i])
		temp[j++] = backup[i++];
	temp[j] = '\0';
	free(backup);
	return (temp);
}

char	*ft_reader(int fd, char *backup)
{
	char	*buffer;
	int		b;

	buffer = malloc(BUFFER_SIZE + 1);
	buffer[0] = '\0';
	b = 1;
	while (b && !(ft_strchr(backup, '\n')))
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b < 0)
		{
			free(backup);
			backup = (NULL);
			free(buffer);
			return (0);
		}
		buffer[b] = '\0';
		if (!(backup))
			backup = ft_strdup(buffer);
		else
			backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	backup[fd] = ft_reader(fd, backup[fd]);
	if (!(backup[fd]))
	{
		free(backup[fd]);
		backup[fd] = (NULL);
		return (0);
	}
	line = set_line(backup[fd]);
	backup[fd] = set_strnig(backup[fd]);
	if (!(line[0]))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
