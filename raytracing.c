/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:54:48 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 13:32:25 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/rtv1.h"
#include "./Constructs/constructs.h"

t_gameobject	*trace(t_ray *ray, t_app *app, double *n)
{
	int				i;
	t_gameobject	*hit_object;
	t_vector3		hit_point;
	t_vector3		new_direction;

	i = -1;
	hit_object = NULL;
	while (++i < app->gameobjectcount)
	{
		if (intersect_cone(ray, &app->gameobjects[i], n) != NULL ||
			intersect_sphere(ray, &app->gameobjects[i], n) != NULL ||
			intersect_plane(ray, &app->gameobjects[i], n) != NULL ||
			intersect_cylinder(ray, &app->gameobjects[i], n) != NULL)
			hit_object = &app->gameobjects[i];
	}
	return (hit_object);
}

void			init_matrices(t_app *app)
{
	int			i;
	t_matrix	m;

	i = -1;
	while (++i < app->gameobjectcount)
	{
		app->gameobjects[i].transform.to_local = set_matrix_identity();
		app->gameobjects[i].transform.to_world = rotate_around_x(
				app->gameobjects[i].transform.rotation.x);
		m = rotate_around_y(app->gameobjects[i].transform.rotation.y);
		app->gameobjects[i].transform.to_world = matrix_multiply(
				app->gameobjects[i].transform.to_world, m);
		m = rotate_around_z(app->gameobjects[i].transform.rotation.z);
		app->gameobjects[i].transform.to_world = matrix_multiply(
				app->gameobjects[i].transform.to_world, m);
		m = set_matrix_identity();
		m[3][0] = app->gameobjects[i].transform.position.x;
		m[3][1] = app->gameobjects[i].transform.position.y;
		m[3][2] = app->gameobjects[i].transform.position.z;
		app->gameobjects[i].transform.to_world = matrix_multiply(
				app->gameobjects[i].transform.to_world, m);
		matrix_inverse(app->gameobjects[i].transform.to_world,
				app->gameobjects[i].transform.to_local);
	}
}

t_gameobject	*prepare_camera(t_app *app, t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < app->gameobjectcount)
	{
		if (app->gameobjects[i].object_type == T_CAMERA)
		{
			ray->origin = app->gameobjects[i].transform.position;
			ray->direction.z = -1;
			return (&app->gameobjects[i]);
		}
	}
	return (NULL);
}

void			raytracing(t_app *app)
{
	int				co[2];
	t_gameobject	camera;
	t_ray			ray;

	init_matrices(app);
	camera = *prepare_camera(app, &ray);
	co[1] = -1;
	while (++co[1] < HEIGHT)
	{
		co[0] = -1;
		while (++co[0] < WIDTH)
		{
			ray.direction.x = (2 * (co[0] + 0.5) * INVW - 1) *
			WIDTH * INVH * ANG;
			ray.direction.y = (1 - 2 * (co[1] + 0.5) * INVH) * ANG;
			ray.direction.z = -1;
			ray.direction = transform_rotation(camera.transform.to_local,
					ray.direction);
			ft_normalize(&ray.direction);
			putpixelimage(app->mlx.image, WIDTH, co,
			get_colour_hit(&ray, app));
		}
	}
	mlx_put_image_to_window(app->mlx.mlx, app->mlx.window,
			app->mlx.image->img, 0, 0);
}
