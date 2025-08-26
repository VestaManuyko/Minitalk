/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:06:16 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/09 15:17:27 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n, int *cnt);
int		ft_putunsign(unsigned int n, int *cnt);
int		ft_putnbr_base(unsigned int n, char *base, int *cnt);
void	ft_putptr_base(uintptr_t ptr, char *base, int *cnt);
int		ft_putptr(void *ptr, char *base, int *cnt);
int		ft_spcfr_detect(va_list list, char spcfr);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);

#endif
