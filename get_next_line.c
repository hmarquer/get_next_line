/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:39:37 by root              #+#    #+#             */
/*   Updated: 2023/11/13 03:39:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_spoil(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(line) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (line[i])
		str[j++] = line[++i];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_line_clean(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_line_spoiled(char *str, int fd)
{
	char	*buff;
	int		readb;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readb = 1;
	while (!(ft_strchr(str, '\n')) && readb > 0)
	{
		readb = read(fd, buff, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[readb] = '\0';
		str = ft_strjoin_mod(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = get_line_spoiled(buf, fd);
	if (!buf)
		return (NULL);
	ret = get_line_clean(buf);
	buf = get_spoil(buf);
	return (ret);
}

/*int	main(void)
{
	char		*s;
	int		i;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	i = 1;
	while ((s = get_next_line(fd)))
	{
		printf("line [%02d]: %s", i, s);
		free(s);
		i++;
	}
	close(fd);
	return (0);
}*/
