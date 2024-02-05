/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:58:16 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/01 15:13:05 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../util/util.h"
# include <signal.h>
# include <sys/types.h>

void	ft_display_error_kill(void);
void	ft_start(void);
void	ft_end(void);
void	get_received_signal(void);
void	ft_received_send(void);
void	get_send_signal(int pid, char argv);
void	ft_error_sig(void);

#endif
