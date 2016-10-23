# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/06 16:08:31 by daugier           #+#    #+#              #
#    Updated: 2016/10/23 03:08:47 by daugier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

RM	= rm -f

LIB = -L ./libs/libft/ -lft -L ./libs/minilibx_macos/ -lft

HEADER = -I ./include

CC = @gcc -Werror -Wextra -Wall -I./include

MLX = -lmlx -framework OpenGL -framework AppKit 

SRCS = 	srcs/main.c \
		srcs/init_data.c \
		srcs/fractol.c \
		srcs/windows_param.c \
		srcs/mandelbrot.c \
		srcs/julia.c \
		srcs/dodo.c \
		srcs/sierpinski.c \
		srcs/event.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "\x1b[33m[F][F][F][F]  [F][F][F][F]  [F][F][F][F]  [F][F][F][F]  [F][F][F][F][F]  [F][F]      [F][F][F][F]  [F]"
	@echo "\033[33m[R]           [R]      [R]  [R]      [R]  [R]                 [R]           [R][R]   [R]      [R]  [R]"
	@echo "\033[33m[A]           [A]      [A]  [A]      [A]  [A]                 [A]               [A]  [A]      [A]  [A]"
	@echo "\033[33m[C][C][C]     [C][C][C][c]  [C]      [C]  [C]                 [C]              [C]   [C]      [C]  [C]"
	@echo "\033[33m[T]           [T][T]        [T][T][T][T]  [T]                 [T]             [T]    [T]      [T]  [T]"
	@echo "\033[33m[']           [']  [']      [']      [']  [']                 [']                    [']      [']  [']"
	@echo "\033[33m[O]           [O]    [O]    [O]      [O]  [O]                 [O]                    [O]      [O]  [O]"
	@echo "\033[33m[L]           [L]      [L]  [L]      [L]  [L][L][L][L]        [L]                    [L][L][L][L]  [L][L][L][L] "
	@echo "\033[35m                                                                                                                 By Augier Dorian"
	@make -C libs/libft/
	@echo "\033[34m[OK]\033[36m LIBFT COMPILED"
	@make -C libs/minilibx_macos/
	@echo "\033[34m[OK]\033[36m MINILIBIX_MACOS COMPILED"
	@$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)
	@echo "\033[34m[OK]\033[36m FRACT'OL COMPILED"
	@echo "\033[32m[OK]\033[32m FRACT'OL CREATED, LET'S HAVE FUN GUYS !"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C libs/libft/
	@make clean -C libs/minilibx_macos/
	@echo "\033[31m[OK]\033[31m FRACT'OL FILES O DELETED"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libs/libft/
	@make fclean -C libs/minilibx_macos/
	@echo "\033[31m[OK]\033[31m FRACT'OL DELETED"

re: fclean all
