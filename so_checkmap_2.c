/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checkmap_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:51:34 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/02/11 14:22:43 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_exit(char *message, int status, t_args *vars)
{
	int	i;

	i = 0;
	ft_printf("\033[1;28mError:\033[0m\n\033[1;31m%s\033[0m\n", message);
	if (vars)
	{
		while (vars->map2d[i])
		{
			if (vars->map2d[i])
				free(vars->map2d[i]);
			i++;
		}
		free(vars->map2d);
	}
	exit(status);
}

void	ft_insit_comps(t_cmpts *comps)
{
	comps->c = 0;
	comps->e = 0;
	comps->n = 0;
	comps->p = 0;
	comps->z = 0;
}

void	ft_check_minim(t_args *vars)
{
	t_cmpts	comps;
	int		i;
	int		j;

	i = 0;
	ft_insit_comps(&comps);
	while (vars->map2d[i])
	{
		j = 0;
		while (vars->map2d[i][j])
		{
			if (vars->map2d[i][j] == 'C')
				comps.c++;
			if (vars->map2d[i][j] == 'E')
				comps.e++;
			if (vars->map2d[i][j] == 'P')
				comps.p++;
			j++;
		}
		i++;
	}
	if ((comps.c == 0) || (comps.e != 1) || (comps.p != 1))
		my_exit("The map requirements aren't valid.", 1, vars);
}

void	ft_check_rect(t_args *vars, const char *map)
{
	char	*last_line;
	int		lines;
	int		curr;
	int		ret;
	int		i;

	i = 0;
	lines = ft_countlines(map);
	last_line = vars->map2d[lines - 1];
	i = ft_strlen(last_line);
	if (last_line[i - 1] == '\n')
		my_exit("The map format is not valid.", 1, vars);
	i = 0;
	ret = 0;
	curr = ft_strlen(vars->map2d[i]);
	i++;
	while (i < (lines - 1))
	{
		if (curr != (int) ft_strlen(vars->map2d[i]))
			ret++;
		curr = ft_strlen(vars->map2d[i++]);
	}
	ret += 1 * ((int)(ft_strlen(vars->map2d[i]) + 1) != curr);
	if (ret != 0)
		my_exit("The map format is not valid.", 1, vars);
}

void	ft_check_all(const char *map, t_args *vars)
{
	ft_check_walls(vars, map);
	ft_check_rect(vars, map);
	ft_check_minim(vars);
	ft_check_strange(vars);
	if (!(ft_check_path(map)))
		my_exit("There is no possible path in the map.", 1, vars);
	if (!(ft_check_name(map)))
		my_exit("The map extension is not valid.", 1, vars);
}
