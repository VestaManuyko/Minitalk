/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:10:10 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/29 15:44:35 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	f(unsigned int i, char *c)
{
    (void) i;
	char	a = (char) *c;

    if (*c >= 'a' && *c <= 'z')
        *c = a - 32;
	else if (*c >= 'A' && *c <= 'Z')
        *c = a +32;
}

#include <stdio.h>

int main(void)
{
    char    s[] = "pussy, money, wEeD!!!";
    ft_striteri(s, f);
    printf("%s\n", s);
    return (0);
}
*/
