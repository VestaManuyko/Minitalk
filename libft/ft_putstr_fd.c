/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:27 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/04 16:39:53 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen((const char *)s));
}
/*
int main(void)
{
	char	s[] = "LOL or LMAO?";
	ft_putstr_fd(s, 1);
	return (0);
}
*/
