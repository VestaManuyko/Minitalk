/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:46 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/15 19:13:51 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*si;
	size_t			i;

	i = 0;
	s = (unsigned char *)s1;
	si = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && s[i] == si[i])
		i++;
	if (i == n)
		return (0);
	return (s[i] - si[i]);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s1 = "hello\0l";
    char *s2 = "hello\0k";
    char *s3 = "hella";
    char *s4 = "hellp";
    char *s5 = "\0\0\0\0\0\0\0\0aze";
    char *s6 = "\0\0\0\0\0\0\0\0aqs";

    printf("Comparing \"%s\" and \"%s\": %d\n", s5, s6, ft_memcmp(s5, s6, 9));
    //printf("Comparing \"%s\" and \"%s\": %d\n", s1, s3, ft_memcmp(s1, s3, 5));
    //printf("Comparing \"%s\" and \"%s\": %d\n", s1, s4, memcmp(s1, s4, 6));
    //printf("Comparing \"%s\" and \"%s\": %d\n", s1, s5, memcmp(s1, s5, 5));
    printf("Comparing \"%s\" and \"%s\": %d\n", s5, s6, memcmp(s5, s6, 9));
    return 0;
}
*/
