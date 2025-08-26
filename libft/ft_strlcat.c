/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:39:39 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/28 18:47:58 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	j;

	src_len = 0;
	dst_len = 0;
	while (src[src_len])
		src_len++;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	if (size > 0)
	{
		j = 0;
		while ((j + 1 + dst_len) < size && src[j])
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = 0;
	}
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int main(void)
{
    char s1[50]= "";
    char *s2 = "1234";
	ft_strlcat(0, s2, 10);
    printf("%s\n", s1);
    return (0);
}
*/
