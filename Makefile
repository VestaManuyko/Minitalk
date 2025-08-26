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
SRC1 =
SRC2 =
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(LIBFT) $(OBJ1)
	@$(CC) $(OBJ1) $(LIBFT) -o $(NAME1)
	@echo "Client made."

$(NAME2) : $(LIBFT) $(OBJ2)
	@$(CC) $(OBJ2) $(LIBFT) -o $(NAME2)
	@echo "Server made."

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