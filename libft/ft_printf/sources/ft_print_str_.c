/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:37:37 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/18 20:16:48 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_str_(char *cp)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!cp)
		cp = "(null)";
	while (cp[i])
	{
		count += ft_print_char(cp[i]);
		i++;
	}
	return (count);
}
