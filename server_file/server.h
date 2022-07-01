/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:22:41 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/01 15:23:29 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <sys/types.h>
# include "../util/util.h"

typedef struct s_bit
{
	char		octect;
	char		*str;
	int			pid_client;
}				t_bit;

void	ft_error(void);
void	ft_start(void);
void	ft_send_msg(void);
void	ft_last_msg(void);
void	ft_start_mgs(void);

#endif
