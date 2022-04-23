# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 08:52:06 by yer-retb          #+#    #+#              #
#    Updated: 2022/04/23 07:17:56 by yer-retb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Werror -Wextra
server = server
client = client
server_bonus = server_bonus
client_bonus = client_bonus
client_src = ft_printf.c ft_putchar.c ft_putnbr.c client.c
server_src = ft_printf.c ft_putchar.c ft_putnbr.c server.c
client_bonus_src = ft_printf.c ft_putchar.c ft_putnbr.c client_bonus.c
server_bonus_src = ft_printf.c ft_putchar.c ft_putnbr.c server_bonus.c
client_obj = $(client_src:.c=.o)
server_obj = $(server_src:.c=.o)
client_bonus_obj = $(client_bonus_src:.c=.o)
server_bonus_obj = $(server_bonus_src:.c=.o)

all :  $(client) $(server) 

$(server) : $(server_obj)
	@$(CC) $(CFLAG) $(server_obj) -o $(server)
	@echo "\033[1;32m server is ready 🛎️"
$(client) : $(client_obj) 
	@$(CC) $(CFLAG) $(client_obj) -o $(client)
	@echo "\033[1;32m client is ready 🖥️"


bonus :  $(client_bonus) $(server_bonus) 

$(server_bonus) : $(server_bonus_obj)
	@$(CC) $(CFLAG) $(server_bonus_obj) -o $(server_bonus)
	@echo "\033[1;34m server_bonus is ready ⌛"
$(client_bonus) : $(client_bonus_obj)
	@$(CC) $(CFLAG) $(client_bonus_obj) -o $(client_bonus)
	@echo "\033[1;34m client_bonus is ready 💻"
	
.c.o :
		@$(CC) $(CFLAG) -c $<
clean :
	rm -rf *.o 
fclean : clean
	rm -rf client server client_bonus server_bonus
re : fclean all bonus
