# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdorner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 08:56:20 by jdorner           #+#    #+#              #
#    Updated: 2018/08/06 10:53:50 by jdorner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = raytracing
HEAD = header/rtv1.h

LIBRARIES = ./Constructs/42/libft/libft.a\
			./Constructs/construct.a\

SRC = 	./main.c\
	 	./input.c\
		./raytracing.c\
		./reader.c\
		./parse.c\
		./lighting.c\
		./Intersections/intersect_plane.c\
		./Intersections/intersect_sphere.c\
		./Intersections/intersect_cylinder.c\
		./Intersections/intersect_cone.c\

OBJ = 	./main.o\
		./input.o\
		./raytracing.o\
		./reader.o\
		./parse.o\
		./lighting.o\
		./intersect_plane.o\
		./intersect_sphere.o\
		./intersect_cylinder.o\
		./intersect_cone.o\
							
GRA = -L -lmlx -framework OpenGL -framework AppKit

# compiling
all: $(NAME)

$(NAME):
	make -C Constructs/
	@$(CC) -c $(SRC)
	@$(CC) -I $(HEADER) $(GRA) $(OBJ) -o $(NAME) $(LIBRARIES)
	make clean

clean:
	@rm -rf $(OBJ) get_next_line.o

fclean: clean
	make fclean -C Constructs/42/libft/
	make fclean -C Constructs/
	@rm -rf $(NAME)

re: fclean all
