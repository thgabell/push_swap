/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:47:51 by thgabell          #+#    #+#             */
/*   Updated: 2022/09/13 17:51:43 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*statiq[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!statiq[fd] || !ft_strchr(statiq[fd], '\n'))
		statiq[fd] = read_text(fd, statiq[fd]);
	if (!statiq[fd])
		return (NULL);
	line = extract_line(statiq[fd]);
	if (!line)
		return (NULL);
	statiq[fd] = next_line(statiq[fd]);
	return (line);
}

char	*read_text(int fd, char *statiq)
{
	int		r;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = 1;
	buf[0] = '\0';
	while (r > 0 && !ft_strchr(buf, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r > 0)
		{
			buf[r] = '\0';
			statiq = ft_strjoin(statiq, buf);
		}
	}
	free(buf);
	if (r < 0)
	{
		free(statiq);
		return (NULL);
	}
	return (statiq);
}

char	*extract_line(char *statiq)
{
	int		i;
	char	*line;

	i = 0;
	while (statiq[i] && statiq[i] != '\n')
		i++;
	if (statiq[i] == '\n')
		line = malloc(sizeof(char) * i + 2);
	if (statiq[i] == '\0')
		line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (statiq[i] != '\0' && statiq[i] != '\n')
	{
		line[i] = statiq[i];
		i++;
	}
	if (statiq[i] == '\n')
	{
		line[i] = statiq[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *statiq)
{
	char	*next_statiq;
	int		i;
	int		j;

	i = 0;
	while (statiq[i] && statiq[i] != '\n')
		i++;
	if (!statiq[i] || !statiq[i + 1])
	{
		free(statiq);
		return (NULL);
	}
	next_statiq = malloc(sizeof(char) * (ft_strlen(statiq) - i));
	if (!next_statiq)
	{
		free(statiq);
		return (NULL);
	}
	i++;
	j = 0;
	while (statiq[i])
		next_statiq[j++] = statiq[i++];
	next_statiq[j] = '\0';
	free(statiq);
	return (next_statiq);
}

/*int	main()
{
	int fd;
	char *line;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{	
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
}*/
