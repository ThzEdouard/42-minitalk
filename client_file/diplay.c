/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diplay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:34:22 by eflaquet          #+#    #+#             */
/*   Updated: 2022/06/28 14:50:07 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_start(void)
{
	putstr(BLUE);
	putstr("------------------start sending and");
	putstr(" receiving signal------------------\n");
	putstr(RESET);
}

void	ft_end(void)
{
	putstr(BLUE);
	putstr("----------------------------------");
	putstr("END---------------------------------\n");
	putstr(RESET);
}

void	ft_received_send(void)
{
    putstr(GREEN);
    putstr("   -------------------------received ");
    putstr("signal-------------------------\n");
    putstr(RESET);
    putstr("           The server has successfully received your signal !\n");
    putstr(GREEN);
    putstr("   -------------------------------");
    putstr("END-------------------------------\n");
    putstr(RESET);
}

void	ft_display_error_kill(void)
{
	putstr(RED);
	putstr("   -------------------------Error ");
	putstr("of kill-------------------------");
	putstr(RESET);
	putstr("\n            An error occurred while sending a signal !\n");
	putstr(RED);
	putstr("   -------------------------------");
	putstr("END-----------------------------\n");
	putstr(RESET);
	ft_end();
	exit(0);
}

void	ft_error_sig(void)
{
	putstr(RED);
	putstr("   -------------------------Error ");
	putstr("of kill-------------------------");
	putstr(RESET);
	putstr("\n            An error Sigaction !\n");
	putstr(RED);
	putstr("   -------------------------------");
	putstr("END-----------------------------\n");
	putstr(RESET);
	ft_end();
	exit(0);
}


