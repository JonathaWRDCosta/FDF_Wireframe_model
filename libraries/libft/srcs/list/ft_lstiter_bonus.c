/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:23:41 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:07:22 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current)
	{
		next = current->next;
		f(current->content);
		current = next;
	}
}

/*
void	print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*list;

    list = NULL;
    ft_lstadd_back(&list, ft_lstnew(strdup("Hello")));
    ft_lstadd_back(&list, ft_lstnew(strdup("World")));
    ft_lstadd_back(&list, ft_lstnew(strdup("Test")));
    ft_lstiter(list, print_content);
    ft_lstclear(&list, free);
    return (0);
}
*/
