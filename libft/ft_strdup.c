/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:24:38 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/28 18:47:23 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	size_t		i;
	char		*dup;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    const char    *s1 = "Hello";
    char    *dup1 = ft_strdup(s1);
    if (dup1 != NULL)
    {
        printf("%s\n", dup1);
        free(dup1);
    }
    const char  * s2 = "Hello";
    char    *dup2 =strdup(s2);
    if (dup2 != NULL)
    {
        printf("%s\n", dup2);
		free(dup2);
	}
	return (0);
}
*/
