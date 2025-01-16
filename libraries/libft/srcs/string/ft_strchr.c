/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 03:42:24 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:34:24 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	t_c;
	int				i;

	i = 0;
	t_c = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == t_c)
			return ((char *)&s[i]);
		i++;
	}
	if (t_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main()
{
  const char *s1 = "Hello, world!";
  const char *s2 = "";
  const char *s3 = "42 is the answer";

  // Test cases
  char *result;

  result = ft_strchr(s1, 'w');
  printf("Test 1: ft_strchr(\"%s\", 'w') = %s\n", s1, result);

  result = ft_strchr(s1, 'z');
  printf("Test 2: ft_strchr(\"%s\", 'z') = %s\n", s1, result);

  result = ft_strchr(s1, '\0');
  printf("Test 3: ft_strchr(\"%s\", '\\0') = %s\n", s1, result);

  result = ft_strchr(s2, 'a');
  printf("Test 4: ft_strchr(\"%s\", 'a') = %s\n", s2, result);

  result = ft_strchr(s3, '4');
  printf("Test 5: ft_strchr(\"%s\", '4') = %s\n", s3, result);

  result = ft_strchr(s3, ' ');
  printf("Test 6: ft_strchr(\"%s\", ' ') = %s\n", s3, result);

  result = ft_strchr(s3, 'r');
  printf("Test 7: ft_strchr(\"%s\", 'r') = %s\n", s3, result);

  result = ft_strchr(s3, 's');
  printf("Test 8: ft_strchr(\"%s\", 's') = %s\n", s3, result);

  result = ft_strchr(s3, 'e');
  printf("Test 9: ft_strchr(\"%s\", 'e') = %s\n", s3, result);

  result = ft_strchr(s3, 'n');
  printf("Test 10: ft_strchr(\"%s\", 'n') = %s\n", s3, result);

  return 0;
}
*/