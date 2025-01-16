/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:28:56 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:29:48 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <limits.h>

// Initializes map properties such as row/column size and anchor points
static void	init_map_props(t_vars *vars)
{
	int	i;

	// Calculate row size (columns) from the first row
	i = 0;
	while (vars->map[0][i] != ULONG_MAX)
		i++;
	vars->row_size = i;
	vars->anchor_x = i / 2;

	// Calculate column size (rows)
	i = 0;
	while (vars->map[i])
		i++;
	vars->col_size = i;
	vars->anchor_y = i / 2;
}

// Initializes the map by loading and parsing the given file
int	init_map(t_vars *vars, char *filename)
{
	char	*raw_map;

	// Validate input
	if (!vars || !filename)
	{
		ft_putstr_fd("Error: Invalid parameters for map initialization.\n", STDERR_FILENO);
		return (-1);
	}

	// Load the raw map as a string
	raw_map = get_raw_map(filename);
	if (!raw_map)
	{
		ft_putstr_fd("Error: Failed to load map file.\n", STDERR_FILENO);
		return (-1);
	}

	// Convert the raw string to a 2D map
	vars->map = split_raw_map(raw_map);
	free(raw_map); // Free the raw map string
	if (!vars->map)
	{
		ft_putstr_fd("Error: Failed to parse map.\n", STDERR_FILENO);
		return (-1);
	}

	// Initialize map properties
	init_map_props(vars);

	ft_putstr_fd("Map initialized successfully.\n", STDOUT_FILENO);
	return (0);
}
