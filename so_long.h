/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:12:02 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/02/02 22:22:30 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"


# define _W 13
# define _A 0
# define _S 1
# define _D 2
# define ESC 53

typedef struct s_comps
{
	int	e;
	int	c;
}	t_comps;

typedef struct s_coords
{
	int	i;
	int	j;
}	t_coords;

typedef struct s_node
{
	struct s_node	*next;
	t_coords		c;
}	t_node;

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
}	t_queue;

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

void	ft_dequeue(t_queue *q);
void	ft_enqueue(t_queue *q, t_coords cor, int *counter, t_coords *visited);
void	ft_init_comps(t_comps *comps);
void	ft_helper(t_queue *q, char **map2d, t_coords *visited, t_comps *comps);
void	ft_bfs(char **map2d, t_comps *comps);
void	ft_remove_e(char **map2d);
int		ft_count_c(char **map2d);
int		ft_is_queue_empty(t_queue *q);
void	ft_init_queue(t_queue *q);
void	ft_init_visited(t_coords *visited);
int		ft_is_visited(int i, int j, t_coords *visited);
int		ft_check_path(const char *map);
void	my_exit(char *message, int status, t_args *vars);
void	ft_insit_comps(t_cmpts *comps);
void	ft_check_minim(t_args *vars);
void	ft_check_rect(t_args *vars, const char *map);
void	ft_check_all(const char *map, t_args *vars);
void	ft_check_ones(char *fu1, char *fu2, t_args *vars);
void	ft_check_walls(t_args *vars, const char *map);
void	ft_check_strange(t_args *vars);
int		ft_check_name(const char *map);
int		ft_countlines(const char *map);
char	**ft_readmap(const char *map);
int		ft_readcoll(char **map2d);
void	ft_set_indexes_12(t_indexes *idxs, int move, int i, int j);
void	ft_map_update(t_args *vars, int move, int i, int j);
int		ft_hook(int keycode, t_args *vars);
void	so_long(const char *map);
int		ft_isvalidcode(int keycode);
int		ft_drawinit(t_args *vars);
void	ft_put_img_to_win(t_args *vars, int i, int j, int move);
char	ft_get_c_postition(t_args *vars, int move, int i, int j);
void	ft_destroy_exit(t_args *vars, int status);
void	*ft_gimg(char curr, t_args *vars);
void	ft_piw(t_args *vars, int curr, int x, int y);
void	ft_init_comps(t_comps *comps);
void	ft_set_imgs(t_imag *x, t_args *vars);
int		ft_quite(t_args *vars);

#endif