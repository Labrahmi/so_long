/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:36:36 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 06:04:09 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_node
{
	int				id;
	int				i;
	int				j;
	struct s_node	*next;
} t_node;


typedef struct s_queue
{
	t_node *head;
	t_node *tail;
}	t_queue;

typedef struct s_visited
{
	int	i, j;
}	t_visited;

void	ft_initialize_q(t_queue *q, char **map2d)
{
	int	i;
	int	j;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->id = 0;
	new_node->next = NULL;
	/* NULL values for start */
	q->head = NULL;
	q->tail = NULL;
	/* Specific case: head and tail must contain 1st Player position */
	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'P')
			{
				new_node->i = i;
				new_node->j = j;
			}
			j++;
		}
		i++;
	}
	q->head = new_node;
	q->tail = new_node;
}

int	ft_is_empty_q(t_queue *q)
{
	if (!(q->head))
	{
		return (1);
	}
	return (0);
}

void	ft_visual_q(t_queue *q)
{
	t_node	*node;

	if (ft_is_empty_q(q))
	{
		printf("Queue is empty!");
		return;
	}
	node = q->head;
	printf("----------------------------------------------\n");
	while (node)
	{
		printf(" id:%d, i:%d, j:%d \n", node->id, node->i, node->j);
		printf("----------------▼----------------\n");
		node = node->next;
	}
	printf("----------------------------------------------\n");
}

void	ft_dequeue(t_queue *q)
{
	t_node	*old_node;

	old_node = q->head;
	if (!(ft_is_empty_q(q)))
	{
		q->head = q->head->next;
	}
	free(old_node);
}

void	ft_enqueue(t_queue *q, int i, int j, t_visited *visited)
{
	static int	ft_curr;
	t_node		*new_node;
	int			new_item;

	new_item = 0;
	int	x = 0;
	while (x < 10240)
	{
		if ((visited[x].i == i) && (visited[x].j == j))
			new_item = 1;
		x++;
	}
	// -
	if (new_item == 1)
		return;
	// -
	ft_curr++;
	visited[ft_curr].i = i;
	visited[ft_curr].j = j;
	new_node = malloc(sizeof(t_node));
	new_node->i = i;
	new_node->j = j;
	new_node->id = ft_curr;
	new_node->next = NULL;
	if (!(ft_is_empty_q(q)))
		q->tail->next = new_node;
	else
		q->head = new_node;
	q->tail = new_node;
}

t_node	*ft_get_curr_node(int curr, t_queue *q)
{
	t_node	*new_node;

	new_node = q->head;
	while (new_node)
	{
		if (new_node->id == curr)
			return (new_node);
		new_node = new_node->next;
	}
	return (0);
}

int	ft_check_visited(int i, int j, t_visited *vis)
{
	int	x;

	x = 0;
	while (x < 10240)
	{
		if ((vis[x].i == i) && (vis[x].j == j))
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_path(char **map2d)
{
	t_node		*curr_node;
	t_visited	visited[10240];
	t_queue		q;
	int			curr;
	int			i;

	curr = 0;	
	ft_initialize_q(&q, map2d);
	while (!(ft_is_empty_q(&q)))
	{
		ft_visual_q(&q);
		curr_node = ft_get_curr_node(curr, &q);
		visited[0].i = curr_node->i;
		visited[0].j = curr_node->j;
		if ((map2d[curr_node->i][curr_node->j + 1]) != '1')
		{
			ft_enqueue(&q, curr_node->i, curr_node->j + 1, visited);
		}
		if ((map2d[curr_node->i][curr_node->j - 1]) != '1')
		{
			ft_enqueue(&q, curr_node->i, curr_node->j - 1, visited);		
		}
		if ((map2d[curr_node->i + 1][curr_node->j]) != '1')
		{
			ft_enqueue(&q, curr_node->i + 1, curr_node->j, visited);
		}
		if ((map2d[curr_node->i - 1][curr_node->j]) != '1')
		{
			ft_enqueue(&q, curr_node->i - 1, curr_node->j, visited);
		}
		ft_dequeue(&q);
		if (!(ft_is_empty_q(&q)))
			curr = q.head->id;
	}
	return (0);
}

// int main(int argc, char const *argv[])
// {
// 	ft_check_path(ft_readmap(argv[1]));
// 	return 0;
// }
