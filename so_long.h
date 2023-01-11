/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:12:02 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/07 17:44:58 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

// =================[Check Map]=====================
int	ft_check_name(const char *map);

// =================[Read Map]======================
char	**ft_readmap(const char *map);
int		ft_countlines(const char *map);
int		ft_readcoll(char **map2d);

// =================[Check Path]====================
int	ft_check_path(char **map2d);


#endif