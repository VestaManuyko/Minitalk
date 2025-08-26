/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:26:49 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/29 15:09:26 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
static char	f(unsigned int i, char c)
{
	(void) i;

	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

#include <stdio.h>

int main(void)
{
	char	*s = "pussy, money, wEeD!!!";
	char	*str = ft_strmapi(s, f);
	printf("%s\n", str);
	free (str);
	return (0);
}
*/
