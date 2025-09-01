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

static void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits = 0;
	static int	sender_pid = 0;

	(void)context;
	if (sender_pid == 0)
		sender_pid = info->si_pid;
	if (info->si_pid != sender_pid)
		kill(info->si_pid, SIGUSR1);
	if (info->si_pid == sender_pid)
	{
		c <<= 1;
		if (signum == SIGUSR2)
			c |= 1;
		if (++bits == 8)
		{
			write(1, &c, 1);
			if (c == '\0')
				sender_pid = 0;
			if (c == '\0')
				write(1, "\n", 1);
			c = 0;
			bits = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	ft_printf("The PID of the server: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit (0);
}
