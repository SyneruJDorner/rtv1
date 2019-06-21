/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector3_identity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:53:12 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:03:37 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

t_vector3	set_vector3_identity(void)
{
	t_vector3	vector;

	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return (vector);
}
