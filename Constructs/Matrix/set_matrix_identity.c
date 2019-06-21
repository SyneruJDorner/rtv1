/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrix_identity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:50:35 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:55:04 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

double	**set_matrix_identity(void)
{
	double	**ret_matrix;
	int		x;
	int		y;
	int		shift_idetity;

	x = -1;
	y = -1;
	shift_idetity = 0;
	ret_matrix = (double**)malloc(sizeof(double) * 4);
	while (++x < 4)
		ret_matrix[x] = (double*)malloc(sizeof(double) * 4);
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (x == shift_idetity)
				ret_matrix[y][x] = 1;
			else
				ret_matrix[y][x] = 0;
		}
		shift_idetity++;
	}
	return (ret_matrix);
}
