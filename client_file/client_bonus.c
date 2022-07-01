/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   client_bonus.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: eflaquet <eflaquet@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/07/01 14:57:52 by eflaquet		  #+#	#+#			 */
/*   Updated: 2022/07/01 15:20:05 by eflaquet		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "client.h"

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

void	listen(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_received_send();
		ft_end();
		exit(0);
	}
	else if (sig == SIGUSR2)
		return ;
}

void	kill_str(int pid, char *str)
{
	static int	i;

	while (*str)
	{
		i = 8;
		while (i--)
		{
			if (*str & 1 << i)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
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
	kill_str(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
