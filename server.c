/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 02:02:51 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/09/01 02:02:53 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum)
{
	static char	c = 0;
	static int	bits = 0;

	c <<= 1;
	if (signum == SIGUSR2)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	ft_printf("The PID of the server: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit (0);
}
