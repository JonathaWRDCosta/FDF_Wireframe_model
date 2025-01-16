/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:36:54 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/09 12:48:05 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}


void sample_function(unsigned int index, char *c) {
    printf("Index: %u, Character: %c\n", index, *c);
}

int main() {
    char str[] = "Hello, World!";
    
    printf("Original string: %s\n", str);
    
    printf("Applying ft_striteri:\n");
    ft_striteri(str, &sample_function);
    
    return 0;
}
