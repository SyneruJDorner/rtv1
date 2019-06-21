/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_axis_radians.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:55:49 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:52:44 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

t_matrix	rotate_around_x(double radians)
{
	t_matrix	matrix;

	matrix = set_matrix_identity();
	matrix[1][1] = cos(radians);
	matrix[1][2] = sin(radians);
	matrix[2][1] = -sin(radians);
	matrix[2][2] = cos(radians);
	return (matrix);
}

t_matrix	rotate_around_y(double radians)
{
	t_matrix	matrix;

	matrix = set_matrix_identity();
	matrix[0][0] = cos(radians);
	matrix[0][2] = -sin(radians);
	matrix[2][0] = sin(radians);
	matrix[2][2] = cos(radians);
	return (matrix);
}

t_matrix	rotate_around_z(double radians)
{
	t_matrix matrix;

	matrix = set_matrix_identity();
	matrix[0][0] = cos(radians);
	matrix[1][0] = sin(radians);
	matrix[0][1] = -sin(radians);
	matrix[1][1] = cos(radians);
	return (matrix);
}
