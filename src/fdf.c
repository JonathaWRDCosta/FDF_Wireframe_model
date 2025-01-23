/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:49:08 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/23 02:00:05 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void clean_up(t_vars *vars)
{
    if (vars->map.data)
        free_ulong_arr(vars->map.data);
}

static void print_error(const char *message)
{
    if (message)
    ft_putstr_fd((char *)message, FDF_STDERR);
}

int main(int argc, char **argv)
{
    t_vars vars;

    vars.map.data = NULL;

    if (argc != 2)
    {
        print_error("Usage: ./fdf <filename>\n");
        return (FDF_EXIT_ERROR);
    }
    if (init_map(&vars, argv[1]) == -1)
    {
        print_error("Error: Failed to initialize map.\n");
        return (FDF_EXIT_ERROR);
    }
    if (init_win(&vars) == -1)
    {
        print_error("Error: Failed to initialize window.\n");
        clean_up(&vars);
        return (FDF_EXIT_ERROR);
    }
    clean_up(&vars);
    return (FDF_EXIT_SUCCESS);
}
