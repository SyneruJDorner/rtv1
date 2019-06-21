/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_multiply_vector3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:59:05 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:08:13 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../constructs.h"

double	vector3_multiply_vector3(t_vector3 v1, t_vector3 v2, double ret)
{
	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ret);
}
