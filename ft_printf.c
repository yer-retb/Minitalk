/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:44:54 by yer-retb          #+#    #+#             */
/*   Updated: 2022/04/23 05:39:26 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_flags(char j, va_list arg)
{
	if (j == 'd' || j == 'i')
		ft_putnbr(va_arg(arg, int));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	g_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_flags(format[i], args);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (g_count);
}
