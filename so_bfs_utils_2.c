/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:43:39 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 19:18:26 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void ft_enqueue(t_queue *q, int i, int j, int *counter, t_coords *visited)
{
	t_node *new_node;

	if ((*counter) != 0)
	{
		if (ft_is_visited(i, j, visited))
			return;
	}
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->c.i = i;
	new_node->c.j = j;
	new_node->next = NULL;
	visited[(*counter)].i = i;
	visited[(*counter)].j = j;
	(*counter)++;
	if (q->tail == NULL)
	{
		q->head = q->tail = new_node;
		return;
	}
	q->tail->next = new_node;
	q->tail = new_node;
}
