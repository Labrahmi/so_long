/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:03:26 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/18 20:16:43 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_print_hexp(unsigned long ul, int *ip)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ul < 16)
	{
		*ip += ft_print_char(hex[ul]);
	}
	else
	{
		ft_print_hexp(ul / 16, ip);
		ft_print_hexp(ul % 16, ip);
	}
}
