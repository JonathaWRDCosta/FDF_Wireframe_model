/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:29:25 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:20:08 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
/*
int main(void)
{
    t_list *head;
    t_list *node1;
    t_list *node2;
    int value1 = 10, value2 = 20, value3 = 30;

    head = ft_lstnew(&value1);
    node1 = ft_lstnew(&value2);
    node2 = ft_lstnew(&value3);

    head->next = node1;
    node1->next = node2;

    printf("List size: %d\n", ft_lstsize(head));

    free(node2);
    free(node1);
    free(head);

    return 0;
}
*/
