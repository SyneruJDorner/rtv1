/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:11:19 by jdorner           #+#    #+#             */
/*   Updated: 2018/08/31 11:11:21 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

int				has_hit_sphere(t_vector3 var, double *t, double *n)
{
	if (!(solve_quadratic(var, t) == 1))
		return (-1);
	if (t[0] < 0)
		t[0] = t[1];
	if (t[0] < 0)
		return (-1);
	if (t[0] > *n)
		return (-1);
	*n = t[0];
	return (0);
}

t_gameobject	*intersect_sphere(t_ray *ray, t_gameobject *obj, double *n)
{
	t_vector3		l;
	t_vector3		var;
	double			t[2];
	t_ray			tempray;

	if (obj->object_type != T_SPHERE)
		return (NULL);
	tempray = *ray;
	tempray.direction = transform_rotation(obj->transform.to_local,
	ray->direction);
	tempray.origin = transform_all(ray->origin, obj->transform.to_local);
	vector3_minus_vector3(obj->transform.position, tempray.origin, &l);
	var.x = ft_dot(tempray.direction, tempray.direction);
	var.y = 2 * ft_dot(tempray.direction, l);
	var.z = ft_dot(l, l) - pow(obj->shape.radius, 2);
	if (has_hit_sphere(var, t, n) != 0)
		return (NULL);
	vector3_multiply_float(tempray.direction, *n, &var);
	vector3_add_vector3(tempray.origin, var, &var);
	sphere_get_normal(var, obj, &obj->normal);
	return (obj);
}

void			sphere_get_normal(t_vector3 point, t_gameobject *obj,
				t_vector3 *ret_normal)
{
	vector3_minus_vector3(point, obj->transform.position, ret_normal);
	ft_normalize(ret_normal);
}
