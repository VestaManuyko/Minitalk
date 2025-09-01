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

static long	atoi_2(const char *nptr, size_t i, int sign)
{
	long	number;

	number = 0;
	if (!nptr[i])
		return (ATOI_ERROR);
	while (nptr[i] && ft_isdigit(nptr[i]))
		number = number * 10 + (nptr[i++] - '0');
	if ((sign == 1 && number > INT_MAX)
		|| (sign == -1 && (-number) < INT_MIN))
		return (ATOI_ERROR);
	return (sign * number);
}

static int	nbr_too_long(const char *nptr)
{
	int	i;

	i = 0;
	if (!nptr[i])
		return (1);
	while (nptr[i])
		i++;
	if (i > 11)
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int		sign;
	size_t	i;

	i = 0;
	if (nbr_too_long(nptr))
		return (ATOI_ERROR);
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
		if (nptr[i] == '-' || nptr[i] == '+')
			break ;
		return (atoi_2(nptr, i, sign));
	}
	return (ATOI_ERROR);
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
