/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:40:41 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/16 21:47:01 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_node;
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	new_node = lst;
	while (new_node)
	{
		current_node = ft_lstnew(f(new_node->content));
		if (!(current_node))
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, current_node);
		new_node = new_node->next;
	}
	return (new_list);
}
