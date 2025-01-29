/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:49:08 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:51:00 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.map.data = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", FDF_STDERR);
		return (FDF_EXIT_ERROR);
	}
	if (init_map(&vars, argv[1]) == -1)
	{
		ft_putstr_fd("Error: Failed to initialize map.\n", FDF_STDERR);
		return (FDF_EXIT_ERROR);
	}
	if (init_win(&vars) == -1)
	{
		ft_putstr_fd("Error: Failed to initialize window.\n", FDF_STDERR);
		free_ulong_arr(vars.map.data);
		return (FDF_EXIT_ERROR);
	}
	free_ulong_arr(vars.map.data);
	return (FDF_EXIT_SUCCESS);
}
