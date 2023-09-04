# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:06:38 by smelicha          #+#    #+#              #
#    Updated: 2023/08/31 15:55:10 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
#Sources:
SRC = main.c src/test.c
#Libraries:
MLX = ./MLX42
MLXLIB = ./MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBMLX = ./MLX42/build/libmlx42.a
#Compiler stuff:
CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all: $(NAME) libmlx

$(NAME): $(OBJ)
	@echo "Linking $@"
	$(CC) $(OBJ) $(LIBMLX) $(MLXLIB) $(FLAGS) -o $(NAME)
	@echo "Done!"

libmlx:
	@git submodule init MLX42
	@git submodule update MLX42
	cmake ./MLX42 -B ./MLX42/build
	cmake --build ./MLX42/build

glfw:
	@git submodule init glfw
	@git submodule update glfw
	cmake ./glfw -B ./glfw/build
	cmake --build ./glfw/build

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)
	@make clean -C ./libraries/minilibx

fclean: clean
	@rm -f $(NAME)

re: fclean all

alltest: all
	@./$(NAME)

test:
	@./$(NAME)

.PHONY: all clean fclean re test