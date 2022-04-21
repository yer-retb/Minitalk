/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:21:16 by yer-retb          #+#    #+#             */
/*   Updated: 2022/04/20 06:19:45 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		g_count;
void	crepting(int sig);
int		ft_power(int nb, int power);
void	printing(void);
void	shifting(int byte, int id);
void	ft_message(char *s, int id);
int		ft_atoi(const char *s);
void	ft_putnbr(long long num);
void	ft_putchar(char c);
void	ft_flags(char j, va_list arg);
int		ft_printf(const char *format, ...);

#endif
