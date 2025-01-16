/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:26:00 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:34 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t_trimmed;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		++i;
	while (j > i && s1[j] && ft_strchr(set, s1[j]))
		--j;
	t_trimmed = ft_substr(s1, i, j - i + 1);
	return (t_trimmed);
}
/*
int main(void)
{
	char s1[] = "   Hello, World!   ";
	char set[] = " ";
	char *result;

	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("Trimmed string: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Trimming failed.\n");
	}

	return 0;
}
*/