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

NAME1 = server
NAME2 = client
NAME3 = server_bonus
NAME4 = client_bonus
LIBFT = libft/libft.a
HEAD = minitalk.h
CC = cc -Wall -Wextra -Werror -g
SRC1 = server.c ft_realloc.c
SRC2 = client.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
BSRC1 = server_bonus.c ft_realloc_bonus.c
BSRC2 = client_bonus.c
BOBJ1 = $(BSRC1:.c=.o)
BOBJ2 = $(BSRC2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(LIBFT) $(OBJ1) $(HEAD)
	@$(CC) $(OBJ1) $(LIBFT) -o $(NAME1)
	@echo "Server made."

$(NAME2) : $(LIBFT) $(OBJ2) $(HEAD)
	@$(CC) $(OBJ2) $(LIBFT) -o $(NAME2)
	@echo "Client made."

%.o : %.c
	@$(CC) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft --no-print-directory

clean :
	@rm -f $(OBJ1) $(OBJ2) $(BOBJ1) $(BOBJ2)
	@$(MAKE) -C libft --no-print-directory clean
	@echo "Cleaned."

fclean : clean
	@rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4)
	@$(MAKE) -C libft --no-print-directory fclean

re : fclean $(NAME1) $(NAME2)

bonus : $(NAME3) $(NAME4)

$(NAME3) : $(LIBFT) $(BOBJ1) $(HEAD)
	@$(CC) $(BOBJ1) $(LIBFT) -o $(NAME3)
	@echo "Server_bonus done."

$(NAME4) : $(LIBFT) $(BOBJ2) $(HEAD)
	@$(CC) $(BOBJ2) $(LIBFT) -o $(NAME4)
	@echo "Client_bonus done."

.PHONY : all clean fclean re bonus