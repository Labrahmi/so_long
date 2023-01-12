/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:06:29 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 22:30:11 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_gimg(char curr, t_args *vars)
{
	int		h;
	int		w;
	void	*img_ptr;

	h = 0;
	w = 0;
	img_ptr = mlx_new_image(vars->mlx, 64, 64);
	if (curr == '0')
		img_ptr = mlx_xpm_file_to_image(vars->mlx, "as/back-0.xpm", &h, &w);
	if (curr == 'C')
		img_ptr = mlx_xpm_file_to_image(vars->mlx, "as/coll-C.xpm", &h, &w);
	if (curr == 'E')
		img_ptr = mlx_xpm_file_to_image(vars->mlx, "as/exit-E.xpm", &h, &w);
	if (curr == 'P')
		img_ptr = mlx_xpm_file_to_image(vars->mlx, "as/play-P.xpm", &h, &w);
	if (curr == '1')
		img_ptr = mlx_xpm_file_to_image(vars->mlx, "as/wall-1.xpm", &h, &w);
	return (img_ptr);
}

void	ft_piw(t_args *vars, int curr, int x, int y)
{
	void	*img;
	void	*base_img;

	img = ft_gimg(curr, vars);
	base_img = ft_gimg('0', vars);
	mlx_put_image_to_window(vars->mlx, vars->win, base_img, x, y);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

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

typedef struct s_indexes
{
	int	ix1;
	int	ix2;
}	t_indexes;

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

char	ft_get_c_postition(t_args *vars, int move, int i, int j)
{
	if (move == _D)
		return (vars->map2d[i][j + 1]);
	if (move == _A)
		return (vars->map2d[i][j - 1]);
	if (move == _S)
		return (vars->map2d[i + 1][j]);
	if (move == _W)
		return (vars->map2d[i - 1][j]);
	return (0);
}

void	ft_destroy_exit(t_args *vars, int status)
{
	free(vars->map2d);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(status);
}

void	ft_put_img_to_win(t_args *vars, int i, int j, int move)
{
	t_imag		x;
	t_indexes	z;
	int			c_postition;

	x.back = ft_gimg('0', vars);
	x.play = ft_gimg('P', vars);
	c_postition = ft_get_c_postition(vars, move, i, j);
	ft_set_indexes_12(&z, move, i, j);
	if ((c_postition == 'E') && (vars->coll == 0))
	{
		mlx_put_image_to_window(vars->mlx, vars->win, x.back, j * 64, i * 64);
		ft_destroy_exit(vars, 0);
	}
	if (!(c_postition == '1' || c_postition == 'E'))
	{
		if ((c_postition) == 'C')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, x.back, z.ix1, z.ix2);
			vars->coll--;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, x.back, j * 64, i * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, x.play, z.ix1, z.ix2);
		ft_map_update(vars, move, i, j);
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
	mlx_hook(vars.win, 2, 1L<<0, ft_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, const char *argv[])
{
	if (argc > 1)
		so_long(argv[1]);
	return (0);
}
