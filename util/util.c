/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:43:10 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/04 19:22:39 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_atoi(const char *c)
{
	int	x;

	if (!c)
		return (-1);
	x = 0;
	while (*c >= 48 && *c <= 57)
		x = x * 10 + *c++ - '0';
	return (x);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	putnbr(int c)
{
	char	x;

	x = c + '0';
	if (c < 10)
		write(1, &x, 1);
	else
	{
		putnbr(c / 10);
		putnbr(c % 10);
	}
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*dest;
	int		size;
	int		i;

	size = 0;
	while (s1 && s1[size])
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 2));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		dest[i] = s1[i];
	if (i == -1)
		i++;
	dest[i] = s2;
	dest[size + 1] = 0;
	if (s1)
		free(s1);
	return (dest);
}
