/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:00:33 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/05 12:41:52 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main(void)
{
    t_list *node;
    int *value;

    value = malloc(sizeof(int));
    *value = 42;

    node = ft_lstnew(value);
    if (node)
    {
        printf("Node created with content: %d\n", *(int *)node->content);
    }
    else
    {
        printf("Failed to create node\n");
    }

    free(node->content);
    free(node);
    return 0;
}
*/