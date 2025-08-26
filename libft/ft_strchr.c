/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:11:48 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/03 18:17:54 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "bla bla";
	int	c = 'b';
	printf("%p\n", ft_strchr(s, c));
	if (ft_strchr(s, c))
		printf("A char is found!");
	else
		printf("Not found:(");
	return (0);
}
*/
