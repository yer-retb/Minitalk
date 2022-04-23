/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:59:39 by yer-retb          #+#    #+#             */
/*   Updated: 2022/04/23 07:30:58 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct h_type
{
	int	*tab;
	int	i;

}	t_data;

t_data	g_data;

void	crepting(int sig)
{
	if (sig == SIGUSR1)
	{
		g_data.tab[g_data.i] = 1;
		g_data.i++;
	}
	if (sig == SIGUSR2)
	{
		g_data.tab[g_data.i] = 0;
		g_data.i++;
	}
}

int	ft_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power-- > 0)
		result *= nb;
	return (result);
}

void	printing(void)
{
	int	j;
	int	power;
	int	r;

	j = 0;
	r = 0;
	power = 7;
	while (j < 8)
	{
		r += ft_power(2, power) * g_data.tab[j];
		j++;
		power--;
	}
	write(1, &r, 1);
}

int	main(void)
{
	g_data.tab = malloc(sizeof(int));
	g_data.i = 0;
	ft_printf("The PId 'Bonus' Is %d \n", getpid());
	signal(SIGUSR1, &crepting);
	signal(SIGUSR2, &crepting);
	while (1)
	{
		if (g_data.i == 8)
		{
			printing();
			g_data.i = 0;
		}
		pause();
	}
	free (g_data.tab);
}
