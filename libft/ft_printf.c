/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:11:34 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/18 02:03:53 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	ft_putptr_base(uintptr_t ptr, char *base, int *cnt)
{
	char	c;

	if (ptr > 16)
		ft_putptr_base((ptr / 16), base, cnt);
	c = base[ptr % 16];
	*cnt += write(1, &c, 1);
}

int	ft_putptr(void *ptr, char *base, int *cnt)
{
	char	c;

	if (ptr == NULL)
	{
		*cnt += write(1, "(nil)", 5);
		return (*cnt);
	}
	*cnt += write(1, "0x", 2);
	if ((uintptr_t)ptr > 16)
		ft_putptr_base(((uintptr_t)ptr / 16), base, cnt);
	c = base[(uintptr_t)ptr % 16];
	*cnt += write(1, &c, 1);
	return (*cnt);
}

int	ft_spcfr_detect(va_list list, char spcfr)
{
	int	value;

	value = 0;
	if (spcfr == 'c')
		value += ft_putchar((char)va_arg(list, int));
	else if (spcfr == 's')
		value += ft_putstr((const char *)va_arg(list, char *));
	else if (spcfr == '%')
		value += ft_putchar('%');
	else if (spcfr == 'i' || spcfr == 'd')
		ft_putnbr(va_arg(list, int), &value);
	else if (spcfr == 'u')
		ft_putunsign(va_arg(list, unsigned int), &value);
	else if (spcfr == 'x')
		ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef", &value);
	else if (spcfr == 'X')
		ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF", &value);
	else if (spcfr == 'p')
		ft_putptr(va_arg(list, void *), "0123456789abcdef", &value);
	return (value);
}

int	ft_printf(const char *format, ...)
{
	va_list			list;
	int				return_value;

	return_value = 0;
	if (!format)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (ft_strchr("cspdiuxX%", (int)*(format + 1)))
				return_value += ft_spcfr_detect(list, *(format + 1));
			else
				return (-1);
			format++;
		}
		else
			return_value += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (return_value);
}
