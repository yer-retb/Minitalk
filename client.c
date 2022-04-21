/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 06:29:26 by yer-retb          #+#    #+#             */
/*   Updated: 2022/04/21 07:41:20 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	unsigned long	rsl;
	int				sn;
	int				i;

	sn = 1;
	i = 0;
	rsl = 0;
	while ((s[i] == 32) || (s[i] >= 9 && s[i] <= 13))
		i++;
	if ((s[i] == '-') || (s[i] == '+'))
	{
		if (s[i] == '-')
			sn = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		rsl = rsl * 10 + s[i] - '0';
		i++;
	}
	return (sn * rsl);
}

void	shifting(int byte, int id)
{
	int	i;
	int	c;

	i = 7;
	while (i >= 0)
	{
		c = byte >> i & 1;
		if (c == 0)
			kill(id, SIGUSR2);
		if (c == 1)
			kill(id, SIGUSR1);
		usleep(100);
		i--;
	}
}

void	ft_message(char *s, int id)
{
	int	i;
	int	byte;

	byte = 0;
	i = 0;
	while (s[i])
	{
		byte = (int)s[i];
		shifting(byte, id);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	id;

	if (ac == 3)
	{
		id = ft_atoi(av[1]);
		ft_message(av[2], id);
	}
	return (0);
}
