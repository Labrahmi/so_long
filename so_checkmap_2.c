/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checkmap_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:51:34 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 12:56:49 by ylabrahm         ###   ########.fr       */
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

int	ft_check_minim(t_args *vars)
{
	t_cmpts comps;
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
		my_exit("The map is invalid", 1, vars);
	return 0;
}

void	ft_check_all(const char *map, t_args *vars)
{
	ft_check_minim(vars);
	if (!(ft_check_path(map)))
		my_exit("There is no possible path in the map!", 1, vars);
	
}
