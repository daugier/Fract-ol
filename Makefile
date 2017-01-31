# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/06 16:08:31 by daugier           #+#    #+#              #
#    Updated: 2017/01/31 18:33:06 by daugier          ###   ########.fr        #
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
	make -C libs/libft/
	make -C libs/minilibx_macos/
	$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libs/libft/
	make clean -C libs/minilibx_macos/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/libft/
	make fclean -C libs/minilibx_macos/

re: fclean all
