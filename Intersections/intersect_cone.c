/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:17:04 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/18 13:17:06 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

int				has_hit_cone(t_vector3 var, double *t, double *n)
{
	if (!(solve_quadratic(var, t) == 1))
		return (-1);
	if (t[0] < 0)
		t[0] = t[1];
	if (t[0] < 0 || t[0] > *n)
		return (-1);
	*n = t[0];
	return (0);
}

void			cone_get_normal(t_vector3 point, t_gameobject *obj,
				t_vector3 *ret_normal)
{
	ret_normal->x = point.x;
	ret_normal->y = point.y;
	ret_normal->z = 1;
	*ret_normal = transform_rotation(obj->transform.to_local, *ret_normal);
	ft_normalize(ret_normal);
}

t_vector3			invert_vector(t_vector3 origin)
{
	origin.x = -origin.x;
	origin.y = -origin.y;
	origin.z = -origin.z;
	return origin;
}

t_gameobject	*intersect_cone(t_ray *ray, t_gameobject *obj, double *n)
{
	t_ray			tempray;
	t_vector3		l;
	t_vector3		var;
	double			t[2];
	double			c;

	if (obj->object_type != T_CONE)
		return (NULL);
	c = pow(obj->shape.radius / obj->shape.height, 2);
	tempray.direction = transform_rotation(obj->transform.to_local,
	ray->direction);
	tempray.origin = transform_all(ray->origin, obj->transform.to_local);
	tempray.origin = invert_vector(tempray.origin);
	var.x = pow(tempray.direction.x, 2) + pow(tempray.direction.y, 2) -
	(c * (obj->shape.radius) * pow(tempray.direction.z, 2));
	var.y = 2 * (tempray.direction.x * tempray.origin.x + tempray.direction.y *
	tempray.origin.y) - (c * tempray.origin.z * tempray.direction.z);
	var.z = (tempray.origin.x * tempray.origin.x + tempray.origin.y *
	tempray.origin.y) - ((0.125f * c) * pow(tempray.origin.z, 2));
	if (has_hit_cone(var, t, n) != 0)
		return (NULL);
	vector3_multiply_float(tempray.direction, *n, &var);
	vector3_minus_vector3(tempray.origin, var, &var);
	cone_get_normal(var, obj, &obj->normal);
	return (obj);
}
