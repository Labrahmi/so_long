/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:49:41 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:49:51 by ylabrahm         ###   ########.fr       */
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
