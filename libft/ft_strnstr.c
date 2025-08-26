/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:13:48 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/04 16:35:15 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j]
				&& big[i + j] && little[j]
				&& i + j < len)
				j++;
			if (little[j] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int main(void)
{
	char	*s1 = "Hello World";
	char	*s2 = "Hello";
	char	*s3 = "";
	printf("%s\n", strnstr(s1, s2, 4));
	printf("%s\n", strnstr(s1, s2, 5));
	printf("%s\n", strnstr(s1, s2, 6));
	printf("%s\n", strnstr(s1, s3, 2));
	printf("%s\n", strnstr(s2, s3, 4));
	printf("Mine: \n");
	char    *so1 = "Hello World";
    char    *so2 = "Hello";
    char    *so3 = "";
    printf("%s\n", ft_strnstr(so1, so2, 4));
    printf("%s\n", ft_strnstr(so1, so2, 5));
    printf("%s\n", ft_strnstr(so1, so2, 6));
    printf("%s\n", ft_strnstr(so1, so3, 2));
    printf("%s\n", ft_strnstr(so2, so3, 4));
	return (0);
}
*/
