/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:43:58 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/28 18:48:13 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		while ((i + 1) < size && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (src_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int main(void)
{
	char s[5] = "1234";
	char s2[7] = "Hello!";
	size_t r = ft_strlcpy(s, s2, -1);
	printf("%zu\n", r);
	return (0);
}
*/
