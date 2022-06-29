//
// Created by Edouard Flaquet on 28/06/2022.
//

#ifndef MINITALK_42_CLIENT_H
#define MINITALK_42_CLIENT_H

#include "../util/util.h"
# include <signal.h>
# include <sys/types.h>

void	ft_display_error_kill(void);
void	ft_start(void);
void	ft_end(void);
void	get_received_signal(void);
void	ft_received_send(void);
void	get_send_signal(int pid, char argv);
void	ft_error_sig(void);

#endif //MINITALK_42_CLIENT_H
