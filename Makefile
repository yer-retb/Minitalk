# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 08:52:06 by yer-retb          #+#    #+#              #
#    Updated: 2022/04/21 07:44:49 by yer-retb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
SCRS = ft_printf.c ft_putchar.c ft_putnbr.c
	
SERVER= server.c

CLIENT= client.c

OBJ = $(SCRS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)

$(OBJ) : $(SCRS)
	$(CC) $(CFLAG) -c $(SCRS)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAG) $(NAME) $(CLIENT) -o client
	$(CC) $(CFLAG) $(NAME) $(SERVER) -o server
clean :
	rm -rf *.o 
fclean : clean
	rm -rf $(NAME) client server
re : fclean all