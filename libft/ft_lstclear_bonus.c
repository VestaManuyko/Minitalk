/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:04:24 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/03 17:57:01 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		temp = node->next;
		ft_lstdelone(node, del);
		node = temp;
	}
	*lst = NULL;
}
/*
void	del(void *beep)
{
	free(beep);
}

int main(void)
{
	t_list	*aj = ft_lstnew(ft_strdup("Hello"));
	t_list	*prep = ft_lstnew(ft_strdup("Loser!"));
	aj->next = prep;
	ft_lstclear(&aj, del);
	return (0);
}
*/
