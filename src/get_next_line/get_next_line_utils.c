/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:48:04 by thgabell          #+#    #+#             */
/*   Updated: 2022/09/13 17:50:30 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *statiq, char *buf)
{
	int		i;
	int		j;
	char	*ptr;

	if (!statiq)
	{
		statiq = malloc(sizeof(char));
		statiq[0] = '\0';
	}
	i = -1;
	j = -1;
	ptr = malloc(sizeof(char) * (ft_strlen(statiq) + ft_strlen(buf) + 1));
	if (!ptr)
		return (NULL);
	while (statiq[++i])
		ptr[i] = statiq[i];
	while (buf[++j])
	{
		ptr[j + i] = buf[j];
	}
	ptr[i + j] = '\0';
	free(statiq);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(s) + 1;
	while (i < length)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
		i++;
	}
	return (NULL);
}
