/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:01:18 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/18 20:18:34 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ss;

	if ((count == SIZE_MAX) || (size == SIZE_MAX))
		return (NULL);
	ss = (char *) malloc(size * count);
	if (ss == NULL)
		return (ss);
	ft_bzero(ss, (size * count));
	return ((void *)ss);
}
