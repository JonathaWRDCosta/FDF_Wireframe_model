/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:13:35 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:06 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
/*
int	main(void)
{
	char	test_chars[];
	size_t	i;

	test_chars[] = {'a', 'b', 'c', 'A', 'B', 'C', '1', '!', 'z', 'Z'};
	for (i = 0; i < 10; i++)
	{
		printf("Original: %c, Uppercase: %c\n", test_chars[i],
				ft_toupper(test_chars[i]));
	}
	return (0);
}
*/
