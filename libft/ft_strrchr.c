/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:30:28 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/03 18:20:38 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;
	char	*last;

	i = 0;
	p = (char *)s;
	last = NULL;
	while (p[i])
	{
		if (p[i] == (char)c)
			last = &p[i];
		i++;
	}
	if (p[i] == 0 && c == 0)
		return (&p[i]);
	return (last);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "bla bla";
    int c = '\0';
	printf("%p\n", strrchr(s, c));
    if (strrchr(s, c))
        printf("A char is found!");
    else
        printf("Not found:(");
    return (0);
}
*/
