/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:07:36 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/02 13:02:01 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*node;

	if (!lst)
		return (0);
	len = 0;
	node = lst;
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*v = "hihi";
	t_list	**list = ft_lstnew(v);
	t_list	*kuku = ft_lstnew(v);
	ft_lstaddfront(&list, kuku);
	printf("%d\n", ft_lstsize(kuku));
	return (0);
}
*/
