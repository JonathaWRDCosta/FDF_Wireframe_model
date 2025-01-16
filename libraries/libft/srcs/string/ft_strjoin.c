/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:45:19 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:25:05 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t_s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	t_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (t_s == NULL)
		return (NULL);
	while (s1[i] != '\0')
		t_s[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		t_s[j++] = s2[i++];
	t_s[j] = '\0';
	return (t_s);
}
/*
int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
}
*/