/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_checkmap_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:51:34 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 12:09:52 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_exit(char *message, int status, t_args *vars)
{
	printf("Error:\n\033[1;31m%s\033[0m\n", message);
	free(vars->map2d);
	exit(status);
}

void	ft_check_all(const char *map, t_args *vars)
{
	if (!(ft_check_path(map)))
		my_exit("There is no possible path in the map!", 1, vars);
}
