/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:59:39 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/09/01 17:59:40 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


volatile sig_atomic_t	g_action = 1;

static void	get_binary(unsigned char c, int pid)
{
	char	binary[8];
	int		i;

	i = 7;
	while (i >= 0)
	{
		binary[i] = (c % 2) + 48;
		c /= 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (!g_action)
			usleep(400);
		if (binary[i] == '0')
			kill(pid, SIGUSR1);
		if (binary[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(400);
		g_action = 0;
	}
}

static void	send_message(char *message, int pid)
{
	size_t	i;

	i = 0;
	while (message[i])
	{
		get_binary((unsigned char)message[i], pid);
		i++;
	}
	get_binary('\0', pid);
}

static void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Server busy, please wait\n", 25);
		exit(1);
	}
	if (signum == SIGUSR2)
		g_action = 1;
}

int	main(int argc, char **argv)
{
	long				pid;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	if (argc != 3)
	{
		write(2, "Expected: ./client [PID] \"message\"\n", 35);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == ATOI_ERROR || (kill((int)pid, 0) == -1))
	{
		write(2, "Incorrect PID\n", 14);
		exit(1);
	}
	if (!argv[2][0])
	{
		write(2, "Empty message\n", 14);
		exit(1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_message(argv[2], (int)pid);
}
