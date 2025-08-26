/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:48:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/23 14:22:23 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_extract_line(char **lines)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*lines || !(*lines)[i])
		return (NULL);
	while ((*lines)[i] && (*lines)[i] != '\n')
		i++;
	if ((*lines)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		ft_free_lines(lines);
		return (NULL);
	}
	while (j < i)
	{
		line[j] = (*lines)[j];
		j++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_trim_lines(char *lines)
{
	char	*trimmed;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!lines || !lines[i])
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	if (!lines[i])
		return (NULL);
	trimmed = malloc(ft_strlen(lines + i) + 1);
	if (!trimmed)
		return (NULL);
	while (lines[i])
		trimmed[j++] = lines[i++];
	trimmed[j] = 0;
	free (lines);
	return (trimmed);
}

char	*ft_eof(char **lines, int bytes_read, int *state)
{
	char	*line;

	if (bytes_read == 0)
	{
		*state = 2;
		if (*lines && **lines == 0)
			return (ft_free_lines(lines));
		line = ft_extract_line(lines);
		if (lines)
			ft_free_lines(lines);
		if (line)
			return (line);
		else
			return (NULL);
	}
	if (bytes_read < 0)
		return (ft_free_lines(lines));
	return (NULL);
}

char	*ft_read_line(char **lines, int fd, int *state)
{
	int		bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	char	*tmp;

	while (!ft_check_newline(*lines))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			line = ft_eof(lines, bytes_read, state);
			if (line)
				return (line);
			return (NULL);
		}
		buf[bytes_read] = 0;
		tmp = *lines;
		*lines = ft_strjoin(*lines, buf);
		free (tmp);
		if (!*lines)
			return (NULL);
	}
	return (*lines);
}

char	*get_next_line(int fd, int *state)
{
	static char	*lines;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lines)
	{
		lines = ft_strdup("");
		if (!lines)
			return (NULL);
	}
	if (!ft_check_newline(lines))
	{
		lines = ft_read_line(&lines, fd, state);
		if (!lines)
			return (NULL);
	}
	line = ft_extract_line(&lines);
	tmp = ft_trim_lines(lines);
	if (!tmp)
		ft_free_lines(&lines);
	else
		lines = tmp;
	return (line);
}
