/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:10:36 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 17:51:27 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*t_count_size;
	size_t			i;

	i = 0;
	t_count_size = malloc(count * size);
	if (t_count_size == NULL)
		return (NULL);
	while (i < count * size)
	{
		t_count_size[i] = 0;
		i++;
	}
	return (t_count_size);
}
/*
int	main(void)
{
	int	*arr1;
	int	*arr2;
	int	i;

	arr1 = (int *)ft_calloc(5, sizeof(int));
	arr2 = (int *)ft_calloc(10, sizeof(int));
	if (arr1)
	{
		printf("Teste 1: ");
		i = 0;
		while (i < 5)
		{
			printf("%d ", arr1[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		printf("Erro ao alocar memória para arr1\n");
	}
	if (arr2)
	{
		printf("Teste 2: ");
		i = 0;
		while (i < 10)
		{
			printf("%d ", arr2[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		printf("Erro ao alocar memória para arr2\n");
	}
	free(arr1);
	free(arr2);
	return (0);
}
*/