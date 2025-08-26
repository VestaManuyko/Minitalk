/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:50:24 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/04/29 17:10:58 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n", ft_strlen(argv[1]));
	return (0);
}
*/
