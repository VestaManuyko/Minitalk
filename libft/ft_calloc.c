/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:48:48 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/14 16:53:51 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*x;

	if (size != 0 && (((nmemb * size) / size) != nmemb))
		return (NULL);
	x = malloc(nmemb * size);
	if (x)
		ft_bzero(x, (nmemb * size));
	return (x);
}
/*
#include <stdio.h>

int main(void)
{
	unsigned char	*bla = ft_calloc(5745, 5);
	printf("%p\n", bla);
	free (bla);
	return (0);
}
*/
