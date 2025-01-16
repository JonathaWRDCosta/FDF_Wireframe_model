/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:21:36 by jonathro          #+#    #+#             */
/*   Updated: 2024/11/03 18:06:32 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*
void	del(void *content)
{
    free(content);
}

int	main(void)
{
	t_list	*node;

    node = ft_lstnew(malloc(10));
    if (node)
    {
        ft_lstdelone(node, del);
    }
    return (0);
}
*/
