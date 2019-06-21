/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:49:19 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:39:08 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <math.h>

typedef double	**t_matrix;

double			**set_matrix_identity();
double			**matrix_multiply(double **m1, double **m2);
double			**matrix_divide_matrix(double **m1, double **m2);
double			**matrix_divide_double(double **m1, double val);
int				matrix_inverse(double **m, double **out);
t_matrix		rotate_around_x(double radians);
t_matrix		rotate_around_y(double radians);
t_matrix		rotate_around_z(double radians);
void			free_matrix(t_matrix m);

#endif
