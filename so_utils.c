/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:17:42 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:45:21 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img_to_win(t_args *vars, int i, int j, int move)
{
	int			c_postition;
	t_imag		x;
	t_indexes	z;

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
