/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:31:23 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:47:53 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

#define E(a, b) m[((i + a) % 4)][((j + b) % 4)]

float	invert_function(int i, int j, double **m)
{
	int		o;
	float	inv;

	o = 2 + (i - j);
	i += 4 - o;
	j += 4 + o;
	inv =
	E(1, -1) * E(0, 0) * E(-1, 1)
	+ E(1, 1) * E(0, -1) * E(-1, 0)
	+ E(-1, -1) * E(1, 0) * E(0, 1)
	- E(-1, -1) * E(0, 0) * E(1, 1)
	- E(-1, 1) * E(0, -1) * E(1, 0)
	- E(1, -1) * E(-1, 0) * E(0, 1);
	return (o % 2) ? inv : -inv;
}

int		matrix_inverse(double **m, double **out)
{
	double	inv[4][4];
	int		i;
	int		j;
	double	deternminant;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			inv[i][j] = invert_function(i, j, m);
	}
	deternminant = 0;
	i = -1;
	while (++i < 4)
		deternminant += m[i][0] * inv[0][i];
	if (deternminant == 0)
		return (0);
	deternminant = 1.0 / deternminant;
	i = -1;
	while (++i < 16)
		out[i / 4][i % 4] = inv[i / 4][i % 4] * deternminant;
	return (1);
}
