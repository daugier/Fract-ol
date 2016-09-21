# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/06 16:08:31 by daugier           #+#    #+#              #
#    Updated: 2016/09/21 02:48:24 by daugier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

RM	= rm -f

LIB = -L ./libs/libft/ -lft -L ./libs/minilibx_macos/ -lft

HEADER = -I ./include

CC = @gcc -I./include

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
	@echo "\x1b[33m[F]"
	@echo "\033[33m[R]"
	@echo "\033[33m[A]"
	@echo "\033[33m[C]"
	@echo "\033[33m[T]"
	@echo "\033[33m[']"
	@echo "\033[33m[O]"
	@echo "\033[33m[L]"
	@make -C libs/libft/
	@echo "\033[34m[OK]\033[33m LIBFT COMPILED"
	@make -C libs/minilibx_macos/
	@echo "\033[34m[OK]\033[33m MINILIBIX_MACOS COMPILED"
	@$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)
	@echo "\033[34m[OK]\033[33m FRACT'OL COMPILED"
	@echo "\033[34m[OK]\033[33m FRACT'OL CREATED, LET'S HAVE FUN GUYS !"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C libs/libft/
	@make clean -C libs/minilibx_macos/
	@echo "\033[31m[OK]\033[31m FRACT'OL FILES C DELETED"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libs/libft/
	@make fclean -C libs/minilibx_macos/
	@echo "\033[31m[OK]\033[31m FRACT'OL DELETED"

re: fclean all
