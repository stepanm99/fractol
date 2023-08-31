# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:06:38 by smelicha          #+#    #+#              #
#    Updated: 2023/08/31 14:16:31 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
#Sources:
SRC = main.c src/test.c
#Libraries:
LIBMLX = ./MLX42/build/libmlx42.a
#Compiler stuff:
CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)
	@make clean -C ./libraries/minilibx

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test