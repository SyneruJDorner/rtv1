# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdorner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 13:28:47 by jdorner           #+#    #+#              #
#    Updated: 2018/09/25 15:02:33 by jdorner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = construct.a
CFLAGS = -Wall -Werror -Wextra -I. -c

VECTOR_FILES = Vector/Vector3/set_vector3_identity.c\
			   Vector/Vector3/set_vector3.c\
			   Vector/Vector3/ft_normalize.c\
			   Vector/Vector3/ft_sqrd_length.c\
			   Vector/Vector3/ft_length.c\
			   Vector/Vector3/ft_dot.c\
			   Vector/Vector3/ft_cross.c\
			   Vector/Vector3/ft_magnitude.c\
			   Vector/Vector3/vector_points_to_distance.c\
			   Vector/Vector3/operators/vector3_add_float.c\
			   Vector/Vector3/operators/vector3_add_vector3.c\
			   Vector/Vector3/operators/vector3_minus_vector3.c\
			   Vector/Vector3/operators/vector3_multiply_vector3.c\
			   Vector/Vector3/operators/vector3_multiply_float.c\
			   Vector/Vector3/operators/vector3_divide_vector3.c\
			   Vector/Vector3/operators/vector3_divide_float.c\

VECTOR_OBJ = set_vector3_identity.o\
			 set_vector3.o\
			 ft_normalize.o\
			 ft_sqrd_length.o\
			 ft_length.o\
			 ft_dot.o\
			 ft_cross.o\
			 ft_magnitude.o\
			 vector_points_to_distance.o\
			 vector3_add_float.o\
			 vector3_add_vector3.o\
			 vector3_minus_vector3.o\
			 vector3_multiply_vector3.o\
			 vector3_multiply_float.o\
		     vector3_divide_vector3.o\
		     vector3_divide_float.o\

MATHF_FILES = Mathf/ft_sqr.c\
			  Mathf/ft_sqrt.c\
			  Mathf/solve_quadratic.c\

MATHF_OBJ = ft_sqr.o\
			ft_sqrt.o\
			solve_quadratic.o\

MATRIX_FILES = Matrix/set_matrix_identity.c\
			   Matrix/matrix_inverse.c\
			   Matrix/matrix_multiply.c\
			   Matrix/rotate_around_axis_radians.c\
			   Matrix/free_matrix.c\

MATRIX_OBJ =  set_matrix_identity.o\
			  matrix_inverse.o\
			  matrix_multiply.o\
			  rotate_around_axis_radians.o\
			  free_matrix.o\

TRANSFORM_FILES = Transform/transform_all.c\
				  Transform/transform_rotation.c\

TRANSFORM_OBJ = transform_all.o\
				transform_rotation.o\

CONVERT_FILES = Convert/convert_string_to.c\

CONVERT_OBJ = convert_string_to.o\

FILES = MLX/init_mlx.c\

GNL = 	42/get_next_line/get_next_line.c

OBJECT = 	get_next_line.o\
			init_mlx.o\

all: $(NAME)

$(NAME): $(OBJECT)
	make -C 42/libft/
	ar -rc $(NAME) $(OBJECT) $(VECTOR_OBJ) $(MATHF_OBJ) $(MATRIX_OBJ) $(TRANSFORM_OBJ) $(CONVERT_OBJ)
	make clean

$(OBJECT): $(FILES)
	$(CC) $(CFLAGS) $(FILES) $(VECTOR_FILES) $(MATHF_FILES) $(MATRIX_FILES) $(TRANSFORM_FILES) $(CONVERT_FILES) $(GNL)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
