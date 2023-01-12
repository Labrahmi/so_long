/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:12:02 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 18:31:42 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

#define _W 13
#define _A 0
#define _S 1
#define _D 2
#define ESC 53

typedef struct s_imag
{
	void	*back;
	void	*wall;
	void	*coll;
	void	*play;
	void	*exit;
}	t_imag;

typedef struct s_args
{
	char	**map2d;
	void	*mlx;
	void	*win;
	int		coll;
	t_imag	img;
	int		h;
	int		w;
}	t_args;

// =================[Check Map]=====================
int	ft_check_name(const char *map);

// =================[Read Map]======================
char	**ft_readmap(const char *map);
int		ft_countlines(const char *map);
int		ft_readcoll(char **map2d);

// =================[Check Path]====================
int		ft_check_path(const char *map);

// =================[Check All]====================
void	ft_check_all(const char *map, t_args *vars);

// ===================[Errors]=====================
void	my_exit(char *message, int status, t_args *vars);



#endif