/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:10:58 by jdorner           #+#    #+#             */
/*   Updated: 2018/08/31 11:11:00 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

int				has_hit_cyl(t_vector3 var, double *t, double *n)
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

void			cylinder_get_normal(t_vector3 point, t_gameobject *obj,
				t_vector3 *ret_normal)
{
	ret_normal->x = point.x;
	ret_normal->y = point.y;
	ret_normal->z = 0;
	*ret_normal = transform_rotation(obj->transform.to_local, *ret_normal);
	ft_normalize(ret_normal);
}

t_gameobject	*intersect_cylinder(t_ray *ray, t_gameobject *obj, double *n)
{
	t_ray			tempray;
	t_vector3		l;
	t_vector3		var;
	double			t[2];

	if (obj->object_type != T_CYLINDER)
		return (NULL);
	tempray.direction = transform_rotation(obj->transform.to_local,
	ray->direction);
	tempray.origin = transform_all(ray->origin, obj->transform.to_local);
	tempray.origin.x = -tempray.origin.x;
	tempray.origin.y = -tempray.origin.y;
	tempray.origin.z = -tempray.origin.z;
	var.x = tempray.direction.x * tempray.direction.x +
	tempray.direction.y * tempray.direction.y;
	var.y = 2 * (tempray.direction.x * tempray.origin.x +
	tempray.direction.y * tempray.origin.y);
	var.z = (tempray.origin.x * tempray.origin.x +
	tempray.origin.y * tempray.origin.y) - pow(obj->shape.radius, 2);
	if (has_hit_cyl(var, t, n) != 0)
		return (NULL);
	vector3_multiply_float(tempray.direction, *n, &var);
	vector3_minus_vector3(tempray.origin, var, &var);
	cylinder_get_normal(var, obj, &obj->normal);
	return (obj);
}
