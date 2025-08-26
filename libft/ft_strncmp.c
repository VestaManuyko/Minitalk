/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:07:05 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/15 19:10:58 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			break ;
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *s1 = "Hello";
	char *s2 = "Hell";
	char *s3 = "Hella";
    char *s4 = "hellp";
    char *s5 = "";
    char *s6 = "o";

    printf("Comparing \"%s\" and \"%s\": %d\n", s1, s2, ft_strncmp(s1, s2, 4));
    printf("Comparing \"%s\" and \"%s\": %d\n", s1, s3, ft_strncmp(s1, s3, 5));
    printf("Comparing \"%s\" and \"%s\": %d\n", s1, s4, ft_strncmp(s1, s4, 2));
    printf("Comparing \"%s\" and \"%s\": %d\n", s1, s5, ft_strncmp(s1, s5, 5));
    printf("Comparing \"%s\" and \"%s\": %d\n", s5, s6, ft_strncmp(s5, s6, 1));

	return 0;
}
*/
