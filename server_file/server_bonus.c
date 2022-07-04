/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:20:48 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/04 17:53:37 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_pid_client;

static int	get_pid(int pid)
{
	if (pid <= 0)
		return (1);
	putstr(GREEN);
	putstr("👉 Server pid = ");
	putnbr(pid);
	putstr(" 👈\n");
	putstr(RESET);
	return (0);
}

int	get_received(char octect)
{
	static char	*str = NULL;

	if (!octect)
	{
		if (kill(g_pid_client, SIGUSR1) != 0)
			ft_error();
		if (str)
		{
			putstr(str);
			free(str);
		}
		putstr("\n");
		str = NULL;
		g_pid_client = 0;
		ft_send_msg();
		ft_last_msg();
		return (1);
	}
	str = ft_strjoin(str, octect);
	if (!str)
		exit(0);
	return (0);
}

void	listen(int sig, siginfo_t *info, void *tmp)
{
	static int	i = 0;
	static char	octect = 0;

	(void)tmp;
	if (!g_pid_client)
		g_pid_client = info->si_pid;
	if (sig == SIGUSR2)
	{
		octect <<= 1;
		octect |= 1;
	}
	if (sig == SIGUSR1)
	{
		octect <<= 1;
	}
	if (++i == 8)
	{
		i = 0;
		if (get_received(octect))
			return ;
		octect = 0;
	}
	if (kill(g_pid_client, SIGUSR2) != 0)
		ft_error();
}

int	main(void)
{
	struct sigaction	sa;

	if (get_pid(getpid()))
		exit(0);
	g_pid_client = 0;
	sa.sa_sigaction = listen;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error();
	ft_start();
	ft_start_mgs();
	while (1)
		pause();
	return (0);
}
