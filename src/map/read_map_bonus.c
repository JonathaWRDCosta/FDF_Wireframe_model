/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:55 by jonatha          #+#    #+#             */
/*   Updated: 2025/02/04 00:31:06 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	process_chunk(int fd, char **map)
{
	ssize_t	r_bytes;
	char	*buf;
	char	*temp;

	buf = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	r_bytes = read(fd, buf, BUFFER_SIZE);
	if (r_bytes == -1)
	{
		free(*map);
		free(buf);
		return (-1);
	}
	buf[r_bytes] = '\0';
	temp = ft_strjoin(*map, buf);
	free(*map);
	*map = temp;
	free(buf);
	if (!*map)
		return (-1);
	return (r_bytes);
}

static int	read_file(int fd, char **map)
{
	ssize_t	r_bytes;

	if (!map)
		return (-1);
	*map = ft_strdup("");
	if (!*map)
		return (-1);
	r_bytes = 1;
	while (r_bytes > 0)
	{
		r_bytes = process_chunk(fd, map);
		if (r_bytes == -1)
		{
			free(*map);
			return (-1);
		}
	}
	return (0);
}

char	*get_raw_map(char *filename)
{
	char	*map;
	int		fd;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (read_file(fd, &map) == -1)
	{
		close(fd);
		free(map);
		return (NULL);
	}
	close(fd);
	return (map);
}
