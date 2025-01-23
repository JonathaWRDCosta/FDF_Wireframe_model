/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:39:34 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/23 01:58:16 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

size_t ulong_arr_len(unsigned long *arr)
{
    size_t i = 0;

    while (arr[i] != ULONG_MAX)
        i++;
    return i;
}

static unsigned long get_point(char *point)
{
    unsigned long   ret;
    unsigned int    color;
    char            **point_attrs;
    int             z;

    point_attrs = ft_split(point, ',');
    if (!point_attrs)
        return (ULONG_MAX);

    z = ft_atoi(point_attrs[0]);
    color = (point_attrs[1]) ? atoi_hex(point_attrs[1] + 2) : LINE_COLOR;
    ret = (((unsigned long)z) << 32) | (color);

    free_str_arr(point_attrs);
    return ret;
}

static unsigned long *get_map_row(char *map_row)
{
    unsigned long *row;
    char          **str_row;
    size_t        row_len;
    size_t        i;

    str_row = ft_split(map_row, ' ');
    if (!str_row)
        return (NULL);

    // Calcular o tamanho correto de str_row
    row_len = 0;
    while (str_row[row_len])
        row_len++;

    row = malloc(sizeof(unsigned long) * (row_len + 1));
    if (!row)
    {
        free_str_arr(str_row);
        return (NULL);
    }

    i = 0;
    while (str_row[i])
    {
        row[i] = get_point(str_row[i]);
        if (row[i] == ULONG_MAX) // Verifique falhas em get_point
        {
            free(row);
            free_str_arr(str_row);
            return (NULL);
        }
        i++;
    }

    row[row_len] = ULONG_MAX;
    free_str_arr(str_row);
    return (row);
}


unsigned long **split_raw_map(char *raw_map)
{
    unsigned long **map;
    char          **str_map;
    size_t        col_size;
    size_t        i;

    str_map = ft_split(raw_map, '\n');
    if (!str_map)
    {
        ft_putstr_fd("Error: Failed to split raw map.\n", FDF_STDERR);
        return (NULL);
    }

    col_size = 0;
    while (str_map[col_size])
        col_size++;

    map = malloc((col_size + 1) * sizeof(unsigned long *));
    if (!map)
    {
        free_str_arr(str_map);
        ft_putstr_fd("Error: Failed to allocate memory for map.\n", FDF_STDERR);
        return (NULL);
    }

    i = 0;
    while (str_map[i])
    {
        map[i] = get_map_row(str_map[i]);
        if (!map[i])
        {
            while (i > 0)
                free(map[--i]); // Libera linhas alocadas
            free(map);
            free_str_arr(str_map);
            return (NULL);
        }
        i++;
    }

    map[col_size] = NULL;
    free_str_arr(str_map);
    return (map);
}

