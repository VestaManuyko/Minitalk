/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:59:45 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/09/01 17:59:46 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_str	g_str = {0};

static void	bit_handler(int signum, char *c)
{
	*c <<= 1;
	if (signum == SIGUSR2)
		*c |= 1;
}

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
		kill(info->si_pid, SIGUSR2);
		bit_handler(signum, &c);
		if (++bits == 8)
		{
			g_str.str[g_str.i++] = c;
			if (c == '\0')
				sender_pid = 0;
			if (c == '\0')
				g_str.end = 1;
			c = 0;
			bits = 0;
		}
	}
}

static void	str_create(void)
{
	char	*temp;

	if (!g_str.str)
	{
		g_str.str = ft_calloc(100, 1);
		if (!g_str.str)
		{
			write(2, "Malloc failed\n", 14);
			exit(1);
		}
		g_str.cap = 100;
	}
	else
	{
		temp = g_str.str;
		g_str.str = ft_realloc(temp, g_str.cap, 100);
		if (!g_str.str)
		{
			free(temp);
			write(2, "Realloc failed\n", 15);
			exit(1);
		}
		g_str.cap += 100;
	}
}

static void	print_str(void)
{
	write(1, g_str.str, ft_strlen(g_str.str));
	write(1, "\n", 1);
	if (g_str.str)
		free (g_str.str);
	g_str.end = 0;
	g_str.i = 0;
	g_str.str = NULL;
	str_create();
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	str_create();
	ft_printf("The PID of the server: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		if (g_str.i == g_str.cap - 1)
			str_create();
		if (g_str.end == 1)
			print_str();
	}
	if (g_str.str)
		free (g_str.str);
	g_str.str = NULL;
	exit (0);
}
