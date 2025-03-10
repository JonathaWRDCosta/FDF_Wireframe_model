/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:43:15 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:52:42 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

unsigned int	atoi_hex(char *str)
{
	unsigned int	result;
	int				value;

	result = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			value = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			value = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			value = *str - 'A' + 10;
		else
			return (0);
		result = result * 16 + value;
		str++;
	}
	return (result);
}

void	free_ulong_arr(unsigned long **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_str_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
