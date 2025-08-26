/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:35:02 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/03 18:15:43 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_length(int n)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (n < 0)
		len = 1;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_get_length(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[len] = 0;
	while (nbr != 0)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
*/
