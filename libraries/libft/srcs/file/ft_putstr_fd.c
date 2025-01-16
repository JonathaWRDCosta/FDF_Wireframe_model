/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:38:56 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/16 17:22:54 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int main()
{
    ft_putstr_fd("Hello, World!", 1);
    ft_putstr_fd("This is a test string.\n", 1);
    ft_putstr_fd("", 1);  // Test with an empty string
    return 0;
}
*/
