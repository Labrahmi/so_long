/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:43:39 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/02/08 14:56:34 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_comps(t_comps *comps)
{
	comps->c = 0;
	comps->e = 0;
}

void	ft_dequeue(t_queue *q)
{
	t_node	*temp;
	int		i;
	int		j;

	if (q->head == NULL)
		return ;
	i = q->head->c.i;
	j = q->head->c.j;
	temp = q->head;
	q->head = q->head->next;
	free(temp);
	if (q->head == NULL)
		q->tail = NULL;
}

void	ft_enqueue(t_queue *q, t_coords cor, int *counter, t_coords *visited)
{
	t_node	*new_node;

	if ((*counter) != 0)
	{
		if (ft_is_visited(cor.i, cor.j, visited))
			return ;
	}
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->c.i = cor.i;
	new_node->c.j = cor.j;
	new_node->next = NULL;
	visited[(*counter)].i = cor.i;
	visited[(*counter)].j = cor.j;
	(*counter)++;
	if (q->tail == NULL)
	{
		q->head = new_node;
		q->tail = new_node;
		return ;
	}
	q->tail->next = new_node;
	q->tail = new_node;
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

void	ft_free_maps(char **map2d)
{
	int	i;

	i = 0;
	if (map2d)
	{
		while (map2d[i])
		{
			free(map2d[i]);
			i++;
		}
		free(map2d);
	}
}
