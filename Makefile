# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:06:38 by smelicha          #+#    #+#              #
#    Updated: 2023/08/29 17:55:52 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCDIR = src

SRC = src/test.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Imlx

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

bonus: all

maintest: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) libraries/minilibx/libmlx.a main.c $(FLAGS)
	@./a.out

maindebug: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAME) libraries/minilibx/libmlx.a main.c -g $(FLAGS) -o prog
	@./prog

.PHONY: all clean fclean re test bonus maintest maindebug