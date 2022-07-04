/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:17:02 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/04 17:19:59 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*g_str;

static void	get_args(int args, int pid, char **argv)
{
	if (args != 3)
	{
		putstr("utilisation : ./client pid 'message'\n");
		ft_end();
		exit(0);
	}
	if (pid <= 0)
	{
		putstr("Error PID\n");
		ft_end();
		exit(0);
	}
	if (!ft_strlen(argv[2]))
	{
		putstr("error : message is clear'\n");
		ft_end();
		exit(0);
	}
}

void	kill_str(int pid)
{
	static int	pid_s = 0;
	static int	i = 8;

	if (!pid_s && pid != -1)
		pid_s = pid;
	if (i == 0)
	{
		g_str++;
		i = 8;
	}
	if (*g_str)
	{
		i--;
		if (*g_str & 1 << i)
			kill(pid_s, SIGUSR2);
		else
			kill(pid_s, SIGUSR1);
	}
	else
	{
		kill(pid_s, SIGUSR1);
		if (i == 0)
			pid_s = 0;
	}
}

void	listen(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_received_send();
		ft_end();
		exit(0);
	}
	else if (sig == SIGUSR2)
	{
		kill_str(-1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = listen;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_start();
	get_args(argc, ft_atoi(argv[1]), argv);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_sig();
	g_str = argv[2];
	kill_str(ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
