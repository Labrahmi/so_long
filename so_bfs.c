/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 05:56:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:44:14 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_queue_empty(t_queue *q)
{
	return (q->head == NULL);
}

void	ft_init_queue(t_queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

void	ft_init_visited(t_coords *visited)
{
	int	i;

	i = 0;
	while (i < 10240)
	{
		visited[i].i = -1;
		visited[i].j = -1;
		i++;
	}
}

int	ft_is_visited(int i, int j, t_coords *visited)
{
	int	k;

	k = 0;
	while (k < 10240)
	{
		if ((visited[k].i == i) && (visited[k].j == j))
			return (1);
		k++;
	}
	return (0);
}

int	ft_check_path(const char *map)
{
	char	**map2d_noe;
	char	**map2d;
	t_comps	without_e;
	t_comps	with_e;
	int		ret;

	ret = 0;
	map2d = ft_readmap(map);
	map2d_noe = ft_readmap(map);
	ft_remove_e(map2d_noe);
	ft_bfs(map2d, &with_e);
	ft_bfs(map2d_noe, &without_e);
	if (with_e.e == 1 && ((without_e.c == with_e.c)))
		ret = 1;
	if (ft_count_c(map2d) != with_e.c)
		ret = 0;
	return (ret);
}
