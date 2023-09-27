# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:06:38 by smelicha          #+#    #+#              #
#    Updated: 2023/09/27 16:05:55 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
#Sources:
SRC = fractol.c src/complex_nr_math.c src/mandelbrot_computation.c \
	src/data_init.c src/controls.c src/julia_computation.c \
	src/complex_nr_math_1.c src/newton_computation.c src/args_helper.c \
	src/errors.c
#Libraries:
MLX = ./MLX42
MLXLIB = ./MLX42/build/libmlx42.a -Iinclude -lglfw -L"./glfw"   #/Users/$(USER)/.brew/opt/glfw/lib/
LIBMLX = ./MLX42/build/libmlx42.a
PRINTFLIB = ./ft_printf/libftprintf.a
MATHLIB = -lm
#Compiler stuff:
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3

OBJ	= $(SRC:.c=.o)

all: printf libmlx glfw $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(OBJ) $(LIBMLX) $(MLXLIB) $(PRINTFLIB) $(MATHLIB) $(FLAGS) -o $(NAME)
	@echo "Done!"

printf:
	@echo "Building ft_printf"
	@git submodule init ft_printf
	@git submodule update ft_printf
	@make all -C ./ft_printf

libmlx:
	@echo "Building MLX42"
	@git submodule init MLX42
	@git submodule update MLX42
	@cmake ./MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build

glfw:
	@echo "Building glfw"
	@git submodule init glfw
	@git submodule update glfw
	@cmake ./glfw -B ./glfw/build
	@cmake --build ./glfw/build

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)
	@make clean -C ./ft_printf


fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./ft_printf

re: fclean all

alltest: all
	@./$(NAME)

test:
	@./$(NAME)

.PHONY: all clean fclean re test