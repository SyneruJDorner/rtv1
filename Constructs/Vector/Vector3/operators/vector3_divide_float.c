/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_divide_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:00:50 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:06:43 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../constructs.h"

void	vector3_divide_float(t_vector3 v1, float value, t_vector3 *ret)
{
	ret->x = v1.x / value;
	ret->y = v1.y / value;
	ret->z = v1.z / value;
}
