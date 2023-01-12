/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checkmap_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:51:34 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 20:06:53 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_cmpts
{
	int	z;
	int	n;
	int	c;
	int	e;
	int	p;
}	t_cmpts;

void	my_exit(char *message, int status, t_args *vars)
{
	printf("\033[1;28mError:\033[0m\n\033[1;31m%s\033[0m\n", message);
	if (vars)
		free(vars->map2d);
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
		my_exit("The map requirements aren't valid", 1, vars);
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
		my_exit("The map format is not valid", 1, vars);
	i = 0;
	ret = 0;
	curr = ft_strlen(vars->map2d[i]);
	i++;
	while (i < (lines - 1))
	{
		if (curr != ft_strlen(vars->map2d[i]))
			ret++;
		curr = ft_strlen(vars->map2d[i++]);
	}
	ret += 1 * ((ft_strlen(vars->map2d[i]) + 1) != curr);
	if (ret != 0)
		my_exit("The map format is not valid", 1, vars);
}

void	ft_check_walls(t_args *vars, const char *map)
{
	int	lines;
	int	ret;
	int	i;
	int	j;

	ret = 0;
	
	
	i = 0;
	while (vars->map2d[0][i] != '\n')
		if (vars->map2d[0][i++] != '1')
			my_exit("The map is not valid (walls)", 1, vars);
	// -
	lines = (ft_countlines(map) - 1);
	while (vars->map2d[lines][i] != '\0')
		if (vars->map2d[lines][i++] != '1')
			my_exit("The map is not valid (walls)", 1, vars);
	// -
	
	i = 0;
	while (i < lines + 1)
	{
		printf("%c", vars->map2d[i][0]);
		i++;
	}
	exit(0);
	




}

void	ft_check_all(const char *map, t_args *vars)
{
	ft_check_rect(vars, map);
	ft_check_minim(vars);
	ft_check_walls(vars, map);
	if (!(ft_check_path(map)))
		my_exit("There is no possible path in the map!", 1, vars);
}
