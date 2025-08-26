/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:00:27 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/03 16:30:18 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		number;
	size_t	i;

	i = 0;
	while (nptr[i])
	{
		while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
			i++;
		sign = 1;
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				sign *= -1;
			i++;
		}
		number = 0;
		while (ft_isdigit(nptr[i]))
			number = number * 10 + (nptr[i++] - '0');
		return (sign * number);
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char	*s = " \r -898750827";
	printf("My:%d\n", ft_atoi(s));
   	printf("Original:%d\n", atoi(s));
	return (0);
}
*/
