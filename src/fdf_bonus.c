/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:46:59 by jonatha          #+#    #+#             */
/*   Updated: 2025/02/03 00:19:37 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = (t_vars){0};
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf_bonus <filename>\n", FDF_STDERR);
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
		free_ulong_arr(vars.map);
		return (FDF_EXIT_ERROR);
	}
	free_ulong_arr(vars.map);
	return (FDF_EXIT_SUCCESS);
}
