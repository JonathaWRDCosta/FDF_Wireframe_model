/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:40:53 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/23 03:26:11 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int read_file(int fd, char **map)
{
    char    *buf;
    ssize_t r_bytes;

    *map = NULL;
    buf = ft_calloc(1, BUFFER_SIZE + 1);
    if (!buf)
        return (-1);

    while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[r_bytes] = '\0';

        if (*map == NULL)
            *map = ft_strdup(buf);
        else
        {
            char *temp = ft_strjoin(*map, buf);
            free(*map);
            *map = temp;
        }

        if (!*map)
        {
            free(buf);
            return (-1);
        }
    }

    free(buf);
    if (r_bytes == -1)
        return (-1);

    return (0);
}

char *get_raw_map(char *filename)
{
    char *map;
    int  fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr_fd("Error: Failed to open file.\n", FDF_STDERR);
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
