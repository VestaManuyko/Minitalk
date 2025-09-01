/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 02:02:56 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/09/01 02:02:57 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_binary(char c, int pid)
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
	while (binary[i])
	{
		if (binary[i] == '0')
			kill(pid, SIGUSR1);
		if (binary[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(350);
	}
}

static void	send_message(char *message, int pid)
{
	size_t	i;

	i = 0;
	while (message[i])
	{
		get_binary(message[i], pid);
		i++;
	}
	get_binary('\0', pid);
}

int	main(int argc, char **argv)
{
	long	pid;

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
	send_message(argv[2], (int)pid);
}
