/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:23:10 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:22 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}
/*
int	main(void)
{
	char	test_chars[];
	size_t	i;

	test_chars[] = {'A', 'B', 'C', 'a', 'b', 'c', '1', '!', 'Z'};
	i = 0;
	while (i < sizeof(test_chars) / sizeof(test_chars[0]))
	{
		printf("Original: %c, Lowercase: %c\n", test_chars[i],
				ft_tolower(test_chars[i]));
		i++;
	}
	return (0);
}
*/
