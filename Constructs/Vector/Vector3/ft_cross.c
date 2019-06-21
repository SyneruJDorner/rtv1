/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:44:47 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:59:24 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

t_vector3	ft_cross(t_vector3 v1, t_vector3 v2, t_vector3 vector)
{
	set_vector3(v1.y * v2.z - v1.z - v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x, &vector);
	return (vector);
}
