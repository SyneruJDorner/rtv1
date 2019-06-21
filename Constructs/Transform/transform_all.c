/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:07:31 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:41:28 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

t_vector3	transform_all(t_vector3 original, t_matrix m)
{
	t_vector3	a;

	a = set_vector3_identity();
	a.x = original.x * m[0][0] + original.y * m[1][0] + original.z * m[2][0]
		+ m[3][0];
	a.y = original.x * m[0][1] + original.y * m[1][1] + original.z * m[2][1]
		+ m[3][1];
	a.z = original.x * m[0][2] + original.y * m[1][2] + original.z * m[2][2]
		+ m[3][2];
	return (a);
}
