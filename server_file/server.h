//
// Created by Edouard Flaquet on 27/06/2022.
//

#ifndef MINITALK_42_SERVER_H
#define MINITALK_42_SERVER_H

# include <signal.h>
# include <sys/types.h>
# include "../util/util.h"

typedef struct s_bit
{
    char        octect;
    char        *str;
    int         pid_client;
}               t_bit;

t_bit   g_bit;

void	ft_error(void);
void    ft_start(void);
void	ft_send_msg(void);
void	ft_last_msg(void);
void	ft_start_mgs(void);

#endif //MINITALK_42_SERVER_H
