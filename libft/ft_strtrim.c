/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:16:20 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/11 18:52:34 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_tlen(char const *s1, char const *set, size_t *st, size_t *e)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = (ft_strlen(s1));
	len = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	while (i != j && s1[--j] > 0 && ft_is_set(s1[j], set))
		;
	*st = i;
	*e = ++j;
	while (i < j)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	total_len;
	size_t	in;

	i = 0;
	j = 0;
	total_len = ft_tlen(s1, set, &i, &j);
	str = malloc(total_len + 1);
	if (!str)
		return (NULL);
	in = 0;
	while (i < j && s1[in])
	{
		str[in] = s1[i];
		i++;
		in++;
	}
	str[in] = 0;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	const char	*s1 = "b!!!!!!!!!!!!";
	const char	*set = "!!!";
	char	*str = ft_strtrim(s1, set);
	printf("%s\n", str);
	return (0);
}
*/
