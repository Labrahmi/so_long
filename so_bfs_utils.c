/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:36 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 21:59:27 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct bfsuv
{
	t_coords	visited[10240];
	t_node		*cun;
	int			i;
	int			j;
}	t_bfsuv;

int	ft_helper_new(t_coords *visited, int *ctr, char **map2d, t_queue *q)
{
	t_coords	cor;

	ft_init_visited(visited);
	ft_init_queue(q);
	cor.i = 0;
	while (map2d[cor.i])
	{
		cor.j = 0;
		while (map2d[cor.i][cor.j])
		{
			if (map2d[cor.i][cor.j] == 'P')
				ft_enqueue(q, cor, ctr, visited);
			cor.j++;
		}
		cor.i++;
	}
	return (0);
}

void	ft_check_now(char curr, t_comps *comps)
{
	if (curr == 'C')
		comps->c += 1;
	if (curr == 'E')
		comps->e += 1;
}

void	ft_set_cors(t_coords *cor, int curr_i, int curr_j)
{
	cor->i = curr_i;
	cor->j = curr_j;
}

void	ft_bfs(char **map2d, t_comps *comps)
{
	t_coords	cor;
	t_bfsuv		new;
	t_queue		q;
	int			ctr;

	ctr = ft_helper_new(new.visited, &ctr, map2d, &q);
	new.cun = q.head;
	while (!(ft_is_queue_empty(&q)))
	{
		ft_check_now(map2d[new.cun->c.i][new.cun->c.j], comps);
		ft_set_cors(&cor, new.cun->c.i, new.cun->c.j + 1);
		if (map2d[new.cun->c.i][new.cun->c.j + 1] != '1')
			ft_enqueue(&q, cor, &ctr, new.visited);
		ft_set_cors(&cor, new.cun->c.i, new.cun->c.j - 1);
		if (map2d[new.cun->c.i][new.cun->c.j - 1] != '1')
			ft_enqueue(&q, cor, &ctr, new.visited);
		ft_set_cors(&cor, new.cun->c.i + 1, new.cun->c.j);
		if (map2d[new.cun->c.i + 1][new.cun->c.j] != '1')
			ft_enqueue(&q, cor, &ctr, new.visited);
		ft_set_cors(&cor, new.cun->c.i - 1, new.cun->c.j);
		if (map2d[new.cun->c.i - 1][new.cun->c.j] != '1')
			ft_enqueue(&q, cor, &ctr, new.visited);
		ft_dequeue(&q);
		new.cun = q.head;
	}
}

void	ft_remove_e(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'E')
				map2d[i][j] = '1';
			j++;
		}
		i++;
	}
}
