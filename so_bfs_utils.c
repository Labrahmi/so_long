/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:36 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 19:15:04 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_comps(t_comps *comps)
{
	comps->c = 0;
	comps->e = 0;
}

void    ft_bfs(char **map2d, t_comps *comps)
{
	t_coords	visited[10240];
	t_node		*current_node;
	int			counter;
	t_queue		q;
	int			i;
	int			j;

	// ft_initVisited(visited);
	ft_init_visited(visited);
	counter = 0;
	// ft_initQueue(&q);
	ft_init_queue(&q);

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'P')
			{
				ft_enqueue(&q, i, j, &counter, visited);
			}
			j++;
		}
		i++;
	}
	
	current_node = q.head;
	
	int	cc = 0;
	int	ee = 0;
	while (!(ft_is_queue_empty(&q)))
	{
		if (map2d[current_node->c.i][current_node->c.j] == 'C')
			cc++;
		if (map2d[current_node->c.i][current_node->c.j] == 'E')
			ee++;
		if (map2d[current_node->c.i][current_node->c.j + 1] != '1')
			ft_enqueue(&q, current_node->c.i, current_node->c.j + 1, &counter, visited);
		if (map2d[current_node->c.i][current_node->c.j - 1] != '1')
			ft_enqueue(&q, current_node->c.i, current_node->c.j - 1, &counter, visited);
		if (map2d[current_node->c.i + 1][current_node->c.j] != '1')
			ft_enqueue(&q, current_node->c.i + 1, current_node->c.j, &counter, visited);
		if (map2d[current_node->c.i - 1][current_node->c.j] != '1')
			ft_enqueue(&q, current_node->c.i - 1, current_node->c.j, &counter, visited);
		ft_dequeue(&q);
		current_node = q.head;
	}
	comps->c = cc;
	comps->e = ee;
}

/*
void	ft_helper(t_queue *q, char **map2d, t_coords *visited, t_comps *comps)
{
	t_node	*current_node;

	ft_init_comps(comps);
	current_node = q->head;
	while (!(ft_is_queue_empty(q)))
	{
		if (map2d[current_node->c.i][current_node->c.j] == 'C')
			comps->c += 1;
		if (map2d[current_node->c.i][current_node->c.j] == 'E')
			comps->e += 1;
		if (map2d[current_node->c.i][current_node->c.j + 1] != '1')
			ft_enqueue(q, current_node->c.i, current_node->c.j + 1, visited);
		if (map2d[current_node->c.i][current_node->c.j - 1] != '1')
			ft_enqueue(q, current_node->c.i, current_node->c.j - 1, visited);
		if (map2d[current_node->c.i + 1][current_node->c.j] != '1')
			ft_enqueue(q, current_node->c.i + 1, current_node->c.j, visited);
		if (map2d[current_node->c.i - 1][current_node->c.j] != '1')
			ft_enqueue(q, current_node->c.i - 1, current_node->c.j, visited);
		ft_dequeue(q);
		current_node = q->head;
	}
}

void	ft_bfs(char **map2d, t_comps *comps)
{
	t_coords	visited[10240];
	int			counter;
	t_queue		q;
	int			i;
	int			j;

	ft_init_visited(visited);
	ft_init_queue(&q);
	counter = 0;
	i = -1;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'P')
				ft_enqueue(&q, i, j, visited);
			j++;
		}
		i++;
	}
	ft_helper(&q, map2d, visited, comps);
}
*/

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

int	ft_count_c(char **map2d)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
