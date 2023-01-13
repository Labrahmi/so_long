/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:12:02 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:13:52 by ylabrahm         ###   ########.fr       */
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

typedef struct wls_v
{
	char	*full_1;
	char	*full_2;
	int		count;
	int		len;
	int		i;
	int		j;
}	t_wls_v;

typedef struct s_cmpts
{
	int	z;
	int	n;
	int	c;
	int	e;
	int	p;
}	t_cmpts;

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

typedef struct s_indexes
{
	int	ix1;
	int	ix2;
}	t_indexes;

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


void	ft_check_ones(char *fu1, char *fu2, t_args *vars);
void	my_exit(char *message, int status, t_args *vars);
void	ft_check_walls(t_args *vars, const char *map);
void	ft_check_strange(t_args *vars);
void	ft_check_minim(t_args *vars);
void	ft_check_rect(t_args *vars, const char *map);
void	ft_check_all(const char *map, t_args *vars);

// -
void	ft_put_img_to_win(t_args *vars, int i, int j, int move);
char	ft_get_c_postition(t_args *vars, int move, int i, int j);
void	ft_piw(t_args *vars, int curr, int x, int y);
void	ft_destroy_exit(t_args *vars, int status);
void	*ft_gimg(char curr, t_args *vars);




#endif