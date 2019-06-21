/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:10:31 by jdorner           #+#    #+#             */
/*   Updated: 2018/08/31 11:10:33 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "../header/rtv1.h"

t_gameobject	*intersect_plane(t_ray *ray, t_gameobject *obj, double *n);
t_gameobject	*intersect_sphere(t_ray *ray, t_gameobject *obj, double *n);
t_gameobject	*intersect_cylinder(t_ray *ray, t_gameobject *obj, double *n);
t_gameobject	*intersect_cone(t_ray *ray, t_gameobject *obj, double *n);
void			sphere_get_normal(t_vector3 point, t_gameobject *obj,
				t_vector3 *ret_normal);

#endif
