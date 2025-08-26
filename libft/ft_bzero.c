/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:29:06 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/03 18:14:09 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[12] = "Hello Lisa!";
	printf("Before: %s\n", s);
	bzero(s, 5);
	printf("After: %s\n", s);
	return (0);
}
*/
