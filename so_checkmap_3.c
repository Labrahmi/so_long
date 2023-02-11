/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checkmap_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:57:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/02/11 14:46:27 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ones(char *fu1, char *fu2, t_args *vars)
{
	int	i;

	i = 0;
	while (fu1[i] && fu1[i] != '\n')
	{
		if (fu1[i] != '1')
		{
			free(fu1);
			my_exit("The map walls are not valid.", 1, vars);
		}
		i++;
	}
	i = 0;
	while (fu2[i])
	{
		if (fu2[i] != '1')
		{
			free(fu2);
			my_exit("The map walls are not valid.", 1, vars);
		}
		i++;
	}
	free(fu1);
	free(fu2);
}

void	ft_check_walls(t_args *vars, const char *map)
{
	t_wls_v	v;

	v.count = ft_countlines(map);
	v.full_1 = ft_strjoin(vars->map2d[v.count - 1], vars->map2d[0]);
	v.full_2 = ft_calloc((v.count * 2) + 1, sizeof(char));
	if (!(v.full_2))
		my_exit("Insufficient memory", 1, NULL);
	v.i = 0;
	v.j = 0;
	while (v.i < v.count)
	{
		v.len = ft_strlen(vars->map2d[v.i]);
		if (v.i == (v.count - 1))
			v.len += 1;
		v.full_2[v.i] = vars->map2d[v.i][v.len - 2];
		v.i++;
	}
	while (v.j < v.count)
	{
		v.full_2[v.i + v.j] = vars->map2d[v.j][0];
		v.j++;
	}
	ft_check_ones(v.full_1, v.full_2, vars);
}

void	ft_check_strange(t_args *vars)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (vars->map2d[i])
	{
		j = 0;
		while (vars->map2d[i][j])
		{
			c = vars->map2d[i][j];
			if (!(c == '1' || c == '0' || c == 'P'
					|| c == 'E' || c == 'C' || c == '\n'))
				my_exit("Strange character is present.", 1, vars);
			j++;
		}
		i++;
	}
}
