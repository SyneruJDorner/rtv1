/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:54:59 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:01:30 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

void	ft_normalize(t_vector3 *vector3)
{
	float length_normalized;

	length_normalized = (float)sqrt(vector3->x * vector3->x +
									vector3->y * vector3->y +
									vector3->z * vector3->z);
	vector3->x /= length_normalized;
	vector3->y /= length_normalized;
	vector3->z /= length_normalized;
}
