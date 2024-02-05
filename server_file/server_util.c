/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:17:28 by eflaquet          #+#    #+#             */
/*   Updated: 2022/06/23 19:45:03 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_start(void)
{
	putstr(RED);
	putstr("👹 MINITALK is start 👹\n");
	putstr(RESET);
}

void	ft_start_mgs(void)
{
	putstr(BLUE);
	putstr("😴 waiting for the first message 😴\n");
	putstr(RESET);
}

void	ft_last_msg(void)
{
	putstr(BLUE);
	putstr("😴 waiting for the next message 😴\n");
	putstr(RESET);
}

void	ft_send_msg(void)
{
	putstr(CYAN);
	putstr("👉 message fully received sent from good reception 👌\n");
	putstr(RESET);
}

void	ft_error(void)
{
	putstr(RED);
	putstr("😱 Error sigaction 😱\n");
	putstr(RESET);
	exit(0);
}
