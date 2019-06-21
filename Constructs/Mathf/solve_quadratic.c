/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:47:45 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:44:45 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

int	solve_quadratic(t_vector3 vector, double t[2])
{
	double	d;

	d = vector.y * vector.y - 4 * vector.x * vector.z;
	if (d < 0)
		return (0);
	d = sqrt(d);
	t[0] = (vector.y + d) / (2 * vector.x);
	t[1] = (vector.y - d) / (2 * vector.x);
	if (t[0] > t[1])
	{
		d = t[0];
		t[0] = t[1];
		t[1] = d;
	}
	return (1);
}
