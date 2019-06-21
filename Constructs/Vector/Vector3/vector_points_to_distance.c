/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_points_to_distance.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:50:38 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:05:32 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

float	vector_points_to_distance(t_vector3 v1, t_vector3 v2)
{
	float	deltax;
	float	deltay;
	float	deltaz;
	float	distance;

	deltax = v1.x - v2.x;
	deltay = v1.y - v2.y;
	deltaz = v1.z - v2.z;
	distance = (float)sqrt(deltax * deltax + deltay * deltay +
			deltaz * deltaz);
	return (distance);
}
