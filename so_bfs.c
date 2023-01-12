/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 05:56:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 07:09:04 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct Coords
{
	int i;
	int j;
};


struct Node
{
	struct Coords c;
	struct Node *next;
};

struct Queue
{
	struct Node *head;
	struct Node *tail;
};

int ft_isQueueEmpty(struct Queue *q)
{
	return (q->head == NULL);
}

void ft_initQueue(struct Queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

void    ft_visual_queue(struct Queue *q)
{
	struct Node *new_node;

	new_node = q->head;
	while (new_node)
	{
		printf("[%d, %d]\n", new_node->c.i, new_node->c.j);
		new_node = new_node->next;
	}
}

void    ft_initVisited(struct Coords *visited)
{
	int i;

	i = 0;
	while (i < 10240)
	{
		visited[i].i = -1;
		visited[i].j = -1;
		i++;
	}
}

int ft_is_visited(int i, int j, struct Coords *visited)
{
	int k;

	k = 0;
	while (k < 10240)
	{
		if ((visited[k].i == i) && (visited[k].j == j))
			return (1);
		k++;
	}
	return (0);
}

void    ft_dequeue(struct Queue *q)
{
	if (q->head == NULL)
	{
		printf("Error: Queue is Empty\n");
		return;
	}
	int i = q->head->c.i;
	int j = q->head->c.j;
	struct Node *temp = q->head;
	q->head = q->head->next;
	free(temp);
	if (q->head == NULL)
		q->tail = NULL;
}

void ft_enqueue(struct Queue *q, int i, int j, int *counter, struct Coords *visited)
{
	struct Node *newNode;

	if ((*counter) != 0)
	{
		if (ft_is_visited(i, j, visited))
		{
			printf("visited: %d, %d\n", i, j);
			return;
		}
	}
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->c.i = i;
	newNode->c.j = j;
	newNode->next = NULL;
	visited[(*counter)].i = i;
	visited[(*counter)].j = j;
	(*counter)++;
	if (q->tail == NULL)
	{
		q->head = q->tail = newNode;
		return;
	}
	q->tail->next = newNode;
	q->tail = newNode;
}

void    ft_bfs(char **map2d)
{
	struct Coords visited[10240];
	struct Queue q;
	int counter;
	int i;
	int j;

	ft_initVisited(visited);
	counter = 0;
	ft_initQueue(&q);

	ft_enqueue(&q, 1, 2, &counter, visited);
	ft_enqueue(&q, 2, 1, &counter, visited);
	ft_enqueue(&q, 1, 3, &counter, visited);
	ft_enqueue(&q, 3, 1, &counter, visited);


	ft_visual_queue(&q);

	printf("counter:%d\n", counter);


	// i = 0;
	// while (map2d[i])
	// {
	// 	j = 0;
	// 	while (map2d[i][j])
	// 	{
	// 		if (map2d[i][j] == 'P')
	// 		{
	// 			ft_enqueue(&q, i, j, &counter, visited);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	// ft_visual_queue(&q);

}

int main(int argc, char const *argv[])
{
	char    **map2d;

	map2d = ft_readmap(argv[1]);
	ft_bfs(map2d);
	return 0;
}