/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:56:16 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/15 19:03:12 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		len = (s_len - start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	char const	*s = "Hellohdfjkehkf";
	char	*str = ft_substr(s, 100, 0);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
