/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:38:36 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:38:38 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

// Converts a hexadecimal string to an unsigned integer
unsigned int	atoi_hex(char *str)
{
	unsigned int	res;
	int				val;

	if (!str || !*str)
		return (0); // Return 0 for NULL or empty strings

	res = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			val = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			val = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			val = *str - 'A' + 10;
		else
		{
			ft_putstr_fd("Error: Invalid hexadecimal character.\n", STDERR_FILENO);
			return (0);
		}
		res = res * 16 + val;
		str++;
	}
	return (res);
}

// Frees a 2D array of unsigned long values
void	free_ulong_arr(unsigned long **arr)
{
	size_t	i;

	if (!arr)
		return;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Frees a 2D array of strings
void	free_str_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Returns the absolute value of an integer
int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
