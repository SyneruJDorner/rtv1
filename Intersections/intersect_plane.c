/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:29:38 by jdorner           #+#    #+#             */
/*   Updated: 2018/08/31 11:29:39 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

void			plane_get_normal(t_gameobject *obj, t_ray *ray,
				t_vector3 *ret_normal)
{
	ret_normal->x = 0;
	ret_normal->y = 0;
	ret_normal->z = 1;
	*ret_normal = transform_rotation(obj->transform.to_local, *ret_normal);
	(void)ray;
}

t_gameobject	*intersect_plane(t_ray *ray, t_gameobject *obj, double *n)
{
	t_ray	tempray;
	double	intersect_distance;
	double	x_inter;
	double	y_inter;

	if (obj->object_type != T_PLANE)
		return (NULL);
	tempray.direction = transform_rotation(obj->transform.to_local,
	ray->direction);
	tempray.origin = transform_all(ray->origin, obj->transform.to_local);
	if (tempray.direction.z == 0)
		return (NULL);
	intersect_distance = -tempray.origin.z / tempray.direction.z;
	if (intersect_distance < 0 || intersect_distance > *n)
		return (NULL);
	x_inter = (tempray.direction.x * intersect_distance + tempray.origin.x +
	obj->shape.width / 2);
	y_inter = (tempray.direction.y * intersect_distance + tempray.origin.y +
	obj->shape.height / 2);
	if (x_inter < 0 || x_inter > obj->shape.width || y_inter < 0 ||
	y_inter > obj->shape.height)
		return (NULL);
	*n = intersect_distance;
	plane_get_normal(obj, &tempray, &obj->normal);
	return (obj);
}
