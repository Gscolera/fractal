# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 23:10:33 by gscolera          #+#    #+#              #
#    Updated: 2019/01/22 04:38:18 by gscolera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fractol
OS		= $(shell uname)
SRC 	= *.c src/*.c

ifeq ($(OS), Linux)
	MLX		= minilibx
	MLX_LNK	= -L $(MLX) -lmlx -lXext -lX11
else
	MLX		= minilibx_macos
	MLX_LNK	= -L $(MLX) -lmlx -framework OpenGL -framework AppKit
endif

INC 	= -Iincludes -I$(MLX)
MATHLNK = = -lm

all:

	gcc $(SRC) $(INC) $(MLX_LNK) $(MATHLINK) -o $(NAME)

clean:
	/bin/rm -f $(NAME)
	make clean -C $(MLX)
