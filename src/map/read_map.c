/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:32:10 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:32:22 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

// Reads the file into a single string
static int	read_file(int fd, char **map)
{
	char	*buf;
	char	*temp;
	ssize_t	r_bytes;

	*map = ft_calloc(1, 1); // Initialize an empty string
	if (!*map)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", STDERR_FILENO);
		return (-1);
	}

	buf = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buf)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", STDERR_FILENO);
		free(*map);
		return (-1);
	}

	while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_bytes] = '\0';
		temp = ft_strjoin(*map, buf);
		free(*map);
		*map = temp;
		if (!*map)
		{
			ft_putstr_fd("Error: Memory allocation failed during concatenation.\n", STDERR_FILENO);
			free(buf);
			return (-1);
		}
	}

	free(buf);
	if (r_bytes == -1)
	{
		ft_putstr_fd("Error: Failed to read file.\n", STDERR_FILENO);
		free(*map);
		*map = NULL;
		return (-1);
	}

	return (0);
}

// Gets the raw map data as a single string
char	*get_raw_map(char *filename)
{
	char	*map;
	int		fd;

	if (!filename)
	{
		ft_putstr_fd("Error: Invalid filename.\n", STDERR_FILENO);
		return (NULL);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Unable to open file.\n", STDERR_FILENO);
		return (NULL);
	}

	if (read_file(fd, &map) == -1)
	{
		close(fd);
		return (NULL);
	}

	close(fd);
	return (map);
}
