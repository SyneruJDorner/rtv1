/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_vector3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:17:10 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:58:43 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

t_vector3	copy_vector3(t_vector3 vector_to_copy)
{
	t_vector3	vector3;

	vector3.x = vector_to_copy.x;
	vector3.y = vector_to_copy.y;
	vector3.z = vector_to_copy.z;
	return (vector3);
}
