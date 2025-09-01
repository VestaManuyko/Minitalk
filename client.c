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

static char	*rev_str(char *binary)
{
	char	*rev_str;
	int		i;
	int		j;

	i = 0;
	j = 7;
	rev_str = malloc(sizeof(char) * 9);
	if (!rev_str)
	{
		write(2, "Malloc of rev_str failed\n", 25);
		exit(1);
	}
	while (j >= 0)
	{
		rev_str[i] = binary[j];
		i++;
		j--;
	}
	rev_str[i] = 0;
	return (rev_str);
}

static char	*get_binary(char c)
{
	char	binary[8];
	int		bin;
	int		i;

	i = 0;
	while (i < 8)
	{
		bin = c % 2;
		c /= 2;
		binary[i] = bin + 48;
		i++;
	}
	return (rev_str(binary));
}

static void	send_message(char *message, int pid)
{
	size_t	i;
	size_t	j;
	char	*binary;

	i = 0;
	while (message[i])
	{
		j = 0;
		binary = get_binary(message[i]);
		while (binary[j])
		{
			if (binary[j] == '0')
				kill(pid, SIGUSR1);
			if (binary[j] == '1')
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
		free(binary);
	}
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
