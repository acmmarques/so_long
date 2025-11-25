# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcardo <andcardo@student.42lisboa.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 22:12:53 by andcardo          #+#    #+#              #
#    Updated: 2025/07/27 10:36:16 by andcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=ft_printf.c hexadecimal_utils.c print_utils.c
OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -f
TEST=main.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: 
	@$(MAKE) -s re
	@$(CC) $(TEST) $(NAME) -g -o exec
	@./exec
	@rm -f exec

.PHONY: all re fclean clean
