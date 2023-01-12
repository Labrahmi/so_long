/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:16:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 16:34:43 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_name(const char *map) 
{
	char	*stand;
	int		stand_len;

	stand = ft_strdup(ft_strrchr(map, '.'));
	stand_len = ft_strlen(stand);
	if (ft_strlen(map) >= 4)
	{
		if (ft_strncmp(".ber", stand, stand_len) == 0)
			return (1);
	}
	return (0);
}

int	ft_countlines(const char *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!(line))
			break;
		i++;
	}
	close(fd);
	return (i);
}

char	**ft_readmap(const char *map)
{
	char	**map2d;
	char	*line;
	int		lines;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	lines = ft_countlines(map);
	map2d = (char **) ft_calloc(lines + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (!(line))
			break;
		map2d[i] = line;
		i++;
	}
	close(fd);
	return (map2d);
}


int ft_readcoll(char **map2d)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
