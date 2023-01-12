/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 05:56:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/12 06:07:30 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct Node
{
    int data;
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

void ft_enqueue(struct Queue *q, int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->tail == NULL)
    {
        q->head = q->tail = newNode;
        return;
    }
    q->tail->next = newNode;
    q->tail = newNode;
}

int ft_dequeue(struct Queue *q)
{
    if (q->head == NULL)
    {
        printf("Error: Queue is Empty\n");
        return -1;
    }
    int value = q->head->data;
    struct Node *temp = q->head;
    q->head = q->head->next;
    free(temp);
    if (q->head == NULL)
        q->tail = NULL;
    return value;
}

void    ft_bfs(char **map2d)
{
    
}

int main(int argc, char const *argv[])
{
    char    **map2d;

	map2d = ft_readmap(argv[1]);
    ft_bfs(map2d);
	return 0;
}