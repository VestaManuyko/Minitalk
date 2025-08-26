/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:08:50 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/07 13:32:57 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		count += write(1, "(null)", 6);
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n, int *cnt)
{
	char	c;

	if (n == INT_MIN)
	{
		*cnt += write(1, "-2147483648", 11);
		return (*cnt);
	}
	if (n < 0)
	{
		*cnt += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr((n / 10), cnt);
	c = (n % 10) + '0';
	*cnt += write(1, &c, 1);
	return (*cnt);
}

int	ft_putunsign(unsigned int n, int *cnt)
{
	char	c;

	if (n > 9)
		ft_putunsign((n / 10), cnt);
	c = (n % 10) + '0';
	*cnt += write(1, &c, 1);
	return (*cnt);
}

int	ft_putnbr_base(unsigned int n, char *base, int *cnt)
{
	char	c;

	if (n > 16)
		ft_putnbr_base((n / 16), base, cnt);
	c = base[n % 16];
	*cnt += write(1, &c, 1);
	return (*cnt);
}
