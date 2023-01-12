/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 05:56:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 16:13:32 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_comps
{
	int e;
	int c;
} t_comps;


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
			return;
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

void    ft_bfs(char **map2d, t_comps *comps)
{
	struct Coords visited[10240];
	struct Node *current_node;
	struct Queue q;
	int counter;
	int i;
	int j;

	ft_initVisited(visited);
	counter = 0;
	ft_initQueue(&q);

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
	while (!(ft_isQueueEmpty(&q)))
	{
		if (map2d[current_node->c.i][current_node->c.j] == 'C')
			cc++;
		if (map2d[current_node->c.i][current_node->c.j] == 'E')
			ee++;
		// -
		if (map2d[current_node->c.i][current_node->c.j + 1] != '1')
			ft_enqueue(&q, current_node->c.i, current_node->c.j + 1, &counter, visited);
		// -
		if (map2d[current_node->c.i][current_node->c.j - 1] != '1')
			ft_enqueue(&q, current_node->c.i, current_node->c.j - 1, &counter, visited);
		// -
		if (map2d[current_node->c.i + 1][current_node->c.j] != '1')
			ft_enqueue(&q, current_node->c.i + 1, current_node->c.j, &counter, visited);
		// -
		if (map2d[current_node->c.i - 1][current_node->c.j] != '1')
			ft_enqueue(&q, current_node->c.i - 1, current_node->c.j, &counter, visited);
		// -
		ft_dequeue(&q);
		current_node = q.head;
	}
	comps->c = cc;
	comps->e = ee;
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

int	ft_count_c(char **map2d)
{
	int i;
	int j;
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
	return c;
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
		
	// printf("with E:(%d)\n", with_e.c);
	// printf("wout E:(%d)\n", without_e.c);
	// printf("cout E:(%d)\n", ft_count_c(map2d));
	// exit(0);
	if (ft_count_c(map2d) != with_e.c)
		ret = 0;
	return (ret);
}
