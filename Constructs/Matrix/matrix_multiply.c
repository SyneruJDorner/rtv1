/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:44:39 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:49:05 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

double	**matrix_multiply(double **m1, double **m2)
{
	double	**ret_matrix;
	int		x;
	int		y;

	y = -1;
	ret_matrix = set_matrix_identity();
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			ret_matrix[y][x] = m1[y][0] * m2[0][x] + m1[y][1] * m2[1][x] +
				m1[y][2] * m2[2][x] + m1[y][3] * m2[3][x];
	}
	free_matrix(m1);
	free_matrix(m2);
	return (ret_matrix);
}
