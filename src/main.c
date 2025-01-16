/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:01:37 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:33:55 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int main(int argc, char *argv[])
{   
    t_vars vars;

    if (argc != 2)
    {
        ft_putstr_fd("Usage: ./fdf <map_file>\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    if (init_map(&vars, argv[1]) == -1)
    {
        ft_putstr_fd("Error: Failed to load map from file.\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    if (init_win(&vars) == -1)
    {
        ft_putstr_fd("Error: Failed to initialize graphical window.\n", STDERR_FILENO);
        if (vars.map)
            free_ulong_arr(vars.map);
        return (EXIT_FAILURE);
    }
    if (vars.map)
        free_ulong_arr(vars.map);
    ft_putstr_fd("FdF terminated successfully.\n", STDOUT_FILENO);
    return (EXIT_SUCCESS);
}
