//
// Created by Edouard Flaquet on 27/06/2022.
//

#include "server.h"

t_bit   g_bit;

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

int    get_received()
{
    if (!g_bit.octect)
    {
        if (kill(g_bit.pid_client, SIGUSR1) != 0)
            ft_error();
        putstr(g_bit.str);
        free(g_bit.str);
        putstr("\n");
        g_bit.str = NULL;
        g_bit.pid_client = 0;
        ft_send_msg();
        ft_last_msg();
        return (1);
    }
    g_bit.str = ft_strjoin(g_bit.str, g_bit.octect);
    if (!g_bit.str)
        exit(0);
    g_bit.octect = 0;
    if (kill(g_bit.pid_client, SIGUSR2) != 0)
        ft_error();
    return (0);
}

void    listen(int sig, siginfo_t *info, void *tmp)
{
    (void)tmp;
    static int				i = 0;

    if (!g_bit.pid_client)
        g_bit.pid_client = info->si_pid;
    if (sig == SIGUSR2)
        g_bit.octect |= 1;
    if (++i == 8)
    {
        i = 0;
        if (get_received())
            return ;
    }
    else
        g_bit.octect <<= 1;
}

int main(void)
{
    struct sigaction sa;

    if (get_pid(getpid()))
        exit(0);
    g_bit.str = NULL;
    g_bit.octect = 0;
    g_bit.pid_client = 0;
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