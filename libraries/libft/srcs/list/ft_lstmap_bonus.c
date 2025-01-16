/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:25:37 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:16:38 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*cont;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cont = f(lst->content);
		tmp = ft_lstnew(cont);
		if (!tmp)
		{
			del(cont);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
/*
void *increment(void *content)
{
    int *value = (int *)content;
    int *new_value = malloc(sizeof(int));
    *new_value = *value + 1;
    return new_value;
}

void delete_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list = NULL;
    t_list *mapped_list = NULL;
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));

    *value1 = 1;
    *value2 = 2;
    *value3 = 3;

    ft_lstadd_back(&list, ft_lstnew(value1));
    ft_lstadd_back(&list, ft_lstnew(value2));
    ft_lstadd_back(&list, ft_lstnew(value3));

    mapped_list = ft_lstmap(list, increment, delete_content);

    t_list *current = mapped_list;
    while (current)
    {
        printf("%d\n", *(int *)current->content);
        current = current->next;
    }

    ft_lstclear(&list, delete_content);
    ft_lstclear(&mapped_list, delete_content);
    return 0;
}

*/