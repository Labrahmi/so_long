/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:06:29 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:13:41 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	ft_drawinit(t_args *vars)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	curr;

	i = 0;
	y = 0;
	while (vars->map2d[i])
	{
		j = 0;
		x = 0;
		while (vars->map2d[i][j])
		{
			curr = vars->map2d[i][j];
			ft_piw(vars, curr, x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
	return (1);
}

int	ft_isvalidcode(int keycode)
{
	if (keycode == _A || keycode == _D
		|| keycode == _W || keycode == _S)
	{
		return (1);
	}
	return (0);
}

void	ft_map_update(t_args *vars, int move, int i, int j)
{
	if (move == _D)
	{
		vars->map2d[i][j] = '0';
		vars->map2d[i][j + 1] = 'P';
	}
	if (move == _A)
	{
		vars->map2d[i][j] = '0';
		vars->map2d[i][j - 1] = 'P';
	}
	if (move == _S)
	{
		vars->map2d[i][j] = '0';
		vars->map2d[i + 1][j] = 'P';
	}
	if (move == _W)
	{
		vars->map2d[i][j] = '0';
		vars->map2d[i - 1][j] = 'P';
	}
}



void	ft_set_indexes_12(t_indexes *idxs, int move, int i, int j)
{
	if (move == _D)
	{
		idxs->ix1 = ((j + 1) * 64);
		idxs->ix2 = (i * 64);
	}
	if (move == _A)
	{
		idxs->ix1 = ((j - 1) * 64);
		idxs->ix2 = (i * 64);
	}
	if (move == _S)
	{
		idxs->ix1 = (j * 64);
		idxs->ix2 = ((i + 1) * 64);
	}
	if (move == _W)
	{
		idxs->ix1 = (j * 64);
		idxs->ix2 = ((i - 1) * 64);
	}
}


int	ft_hook(int keycode, t_args *vars)
{
	int	i;
	int	j;

	if (ft_isvalidcode(keycode))
	{
		i = 0;
		while (vars->map2d[i])
		{
			j = 0;
			while (vars->map2d[i][j])
			{
				if (vars->map2d[i][j] == 'P')
				{
					ft_put_img_to_win(vars, i, j, keycode);
					return (0);
				}
				j++;
			}
			i++;
		}
	}
	if (keycode == ESC)
		ft_destroy_exit(vars, 0);
	return (0);
}

void	so_long(const char *map)
{
	t_args	vars;

	if (!(ft_check_name(map)))
		exit(1);
	vars.map2d = ft_readmap(map);
	vars.coll = ft_readcoll(vars.map2d);
	vars.h = ft_countlines(map);
	vars.w = ft_strlen(vars.map2d[0]) - 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.w * 64), (vars.h * 64), "long");
	ft_check_all(map, &vars);
	ft_drawinit(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, const char *argv[])
{
	if (argc > 1)
		so_long(argv[1]);
	return (0);
}
