/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:29:09 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 00:42:00 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom(t_vars *vars, t_point *point)
{
	if (!vars || !point)
		return ;
	point->x *= vars->zoom;
	point->y *= vars->zoom;
	point->z *= vars->zoom;
}

void	translate(t_vars *vars, t_point *point)
{
	if (!vars || !point)
		return ;
	point->x += vars->map_x;
	point->y -= vars->map_y;
}
