/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:47:11 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:41:40 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

t_vector3	transform_rotation(t_matrix m, t_vector3 direction)
{
	t_vector3	a;

	a = set_vector3_identity();
	a.x = direction.x * m[0][0] + direction.y * m[1][0] + direction.z * m[2][0];
	a.y = direction.x * m[0][1] + direction.y * m[1][1] + direction.z * m[2][1];
	a.z = direction.x * m[0][2] + direction.y * m[1][2] + direction.z * m[2][2];
	return (a);
}
