/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:16:38 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/21 12:45:34 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cat(char *ret_str, const char *s1, const char *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	while (i < len_1)
	{
		ret_str[i] = s1[i];
		i++;
	}
	while (j < len_2)
	{
		ret_str[i] = s2[j];
		j++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	int		s1_len;
	int		s2_len;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret_str = (char *) ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!ret_str)
		return (NULL);
	ft_cat(ret_str, s1, s2);
	return (ret_str);
}
