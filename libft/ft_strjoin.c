/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/28 18:47:45 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum_len;
	char	*str;
	size_t	i;
	size_t	j;

	sum_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sum_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*s1 = "!!!HA";
	char const	*s2 = "HA!!!";
	char	*str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	free (str);
	return (0);
}
*/
