/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:33:54 by sbart             #+#    #+#             */
/*   Updated: 2021/12/21 13:34:49 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rewrite_line(char *line)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!res)
		return (NULL);
	i++;
	while (line[i] != '\0')
		res[j++] = line[i++];
	res[j] = '\0';
	free(line);
	return (res);
}	

char	*ft_enter_line(char *line)
{
	char	*res;
	int		i;

	i = 0;
	if (line == NULL || line[0] == '\0')
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[++i] = '\0';
	i--;
	while (i != -1)
	{
		res[i] = line[i];
		i--;
	}
	return (res);
}

char	*ft_strdup_line(char *line)
{
	char	*res;

	if (!line)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	return (line);
}

int	ft_check_correct(int fd, char *buff)
{
	if (fd < 0 || BUFF_SIZE <= 0 || !buff)
	{
		free (buff);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	char		*res;
	int			check_read;

	line = ft_strdup_line(line);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (ft_check_correct(fd, buff))
		return (NULL);
	check_read = read(fd, buff, BUFF_SIZE);
	while (check_read > 0)
	{
		buff[check_read] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_check_line_feed(line))
			break ;
		check_read = read(fd, buff, BUFF_SIZE);
	}
	free(buff);
	res = ft_enter_line(line);
	line = ft_rewrite_line(line);
	if (res == NULL && check_read <= 0 && line == NULL)
		return (NULL);
	return (res);
}
