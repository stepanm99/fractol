# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:06:38 by smelicha          #+#    #+#              #
#    Updated: 2023/09/07 18:42:41 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
#Sources:
SRC = fractol.c src/complex_nr_math.c src/mandelbrot_computation.c src/data_init.c
#Libraries:
MLX = ./MLX42
MLXLIB = ./MLX42/build/libmlx42.a -Iinclude -lglfw -L"./glfw"   #/Users/$(USER)/.brew/opt/glfw/lib/
LIBMLX = ./MLX42/build/libmlx42.a
MATHLIB = -lm
#Compiler stuff:
CC = cc
FLAGS = -Wall -Wextra -Werror -O3

OBJ	= $(SRC:.c=.o)

all: libmlx glfw $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(OBJ) $(LIBMLX) $(MLXLIB) $(MATHLIB) $(FLAGS) -o $(NAME)
	@echo "Done!"

libmlx:
	@git submodule init MLX42
	@git submodule update MLX42
	@cmake ./MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build

glfw:
	@git submodule init glfw
	@git submodule update glfw
	@cmake ./glfw -B ./glfw/build
	@cmake --build ./glfw/build

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

alltest: all
	@./$(NAME)

test:
	@./$(NAME)

.PHONY: all clean fclean re test