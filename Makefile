# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 17:26:49 by vmanuyko          #+#    #+#              #
#    Updated: 2025/08/26 17:26:50 by vmanuyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
LIBFT = libft/libft.a
CC = cc -Wall -Wextra -Werror
SRC =
OBJ =

all : $(NAME1) $(NAME2)

$(NAME1) :

$(NAME2) :

%.o : %.c
	@$(CC) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft --no-print-directory

clean :
	@rm -f $(OBJ) $(POBJ)
	@$(MAKE) -C libft --no-print-directory clean
	@echo "Cleaned."

fclean : clean
	@rm -f $(NAME1) $(NAME2)
	@$(MAKE) -C libft --no-print-directory fclean