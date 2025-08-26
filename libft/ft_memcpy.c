/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:03 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/15 19:16:10 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*p;

	d = (unsigned char *)dest;
	p = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = p[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	char s[6] = "Hello";
	printf("%s\n", (char *)ft_memcpy(s + 2, s, 4));
	return (0);
}
*/
