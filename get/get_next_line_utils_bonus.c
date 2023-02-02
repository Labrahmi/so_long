/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:22:38 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/12/26 19:41:58 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(int count, int size)
{
	char	*ss;
	int		i;

	ss = (char *) malloc(size * count);
	if (ss == NULL)
		return (ss);
	i = 0;
	while (i < (size * count))
		ss[i++] = 0;
	return ((void *)ss);
}

int	ft_strlen(char *array)
{
	int	i;

	i = 0;
	if (!(array))
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	ft_strchr(char *backup, int c)
{
	int	i;

	i = 0;
	if (backup)
		while (backup[i])
			if (backup[i++] == (char)c)
				return (1);
	return (0);
}

char	*ft_strjoin(char *backup, char *buffer)
{
	char		*temp;
	int			i;
	int			j;

	temp = (char *) malloc(ft_strlen(backup) + ft_strlen(buffer) + 1);
	if (!(temp))
		return (0);
	i = -1;
	j = 0;
	while (backup[++i])
		temp[i] = backup[i];
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(backup);
	return (temp);
}

char	*ft_strdup(char *s1)
{
	char	*ret_pointer;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ret_pointer = (char *) ft_calloc((len + 1), sizeof(char));
	if (!ret_pointer)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret_pointer[i] = s1[i];
	return (ret_pointer);
}
