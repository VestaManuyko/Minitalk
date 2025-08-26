/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:01:05 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/28 18:46:26 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[12] = "Hello Lisa!";
	printf("Before: %s\n", s);
	memset(s, '-', 6);
	printf("After: %s\n", s);
	return (0);
}
*/
