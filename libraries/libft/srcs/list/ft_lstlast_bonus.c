/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:19:24 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:15:11 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*res;

	if (lst == NULL)
		return (NULL);
	res = lst;
	while (res->next != NULL)
		res = res->next;
	return (res);
}
/*
int main(void)
{
    t_list *list = NULL;
    t_list *last_node;

    ft_lstadd_back(&list, ft_lstnew(strdup("Node 1")));
    ft_lstadd_back(&list, ft_lstnew(strdup("Node 2")));
    ft_lstadd_back(&list, ft_lstnew(strdup("Node 3")));

    last_node = ft_lstlast(list);
    if (last_node)
        printf("Last node content: %s\n", (char *)last_node->content);

    ft_lstclear(&list, free);
    return 0;
}
*/
