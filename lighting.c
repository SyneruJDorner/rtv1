/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:33:36 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 13:37:04 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/rtv1.h"

unsigned int		determine_lighting(t_ray *shadow, t_app *app,
		t_gameobject *gameobject)
{
	int				i;
	t_vector3		direction;
	double			n;
	t_gameobject	*light;

	i = -1;
	while (++i < app->gameobjectcount)
		if (app->gameobjects[i].object_type == T_POINTLIGHT)
			light = &app->gameobjects[i];
	vector3_minus_vector3(light->transform.position, shadow->origin,
			&shadow->direction);
	n = ft_length(shadow->direction);
	ft_normalize(&shadow->direction);
	if (trace(shadow, app, &n))
		return (-1);
	return (0);
}

unsigned long		rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

unsigned int		scale_colour(unsigned int hit_colour,
					t_gameobject *hit_object, t_ray *shadow)
{
	t_vector3		vec_colour;
	unsigned int	ret_colour;

	vec_colour = set_vector3_identity();
	vec_colour.x = ((hit_colour >> 16) & 0xFF);
	vec_colour.y = ((hit_colour >> 8) & 0xFF);
	vec_colour.z = ((hit_colour) & 0xFF);
	vec_colour.x = vec_colour.x * ft_abs(ft_dot(hit_object->normal,
				shadow->direction));
	vec_colour.y = vec_colour.y * ft_abs(ft_dot(hit_object->normal,
				shadow->direction));
	vec_colour.z = vec_colour.z * ft_abs(ft_dot(hit_object->normal,
				shadow->direction));
	vec_colour.x = (vec_colour.x > 255) ? 255 : vec_colour.x;
	vec_colour.y = (vec_colour.y > 255) ? 255 : vec_colour.y;
	vec_colour.z = (vec_colour.z > 255) ? 255 : vec_colour.z;
	ret_colour = rgb_to_hex(vec_colour.x, vec_colour.y, vec_colour.z);
	return (ret_colour);
}

unsigned int		get_colour_hit(t_ray *ray, t_app *app)
{
	t_gameobject	*hit_object;
	double			n;
	t_ray			shadow;
	unsigned int	colour;

	colour = 0x000000;
	n = INFINITY;
	hit_object = trace(ray, app, &n);
	if (hit_object != NULL)
	{
		shadow.origin = (t_vector3)
		{
			ray->origin.x + (n * 0.9999999999) * ray->direction.x,
			ray->origin.y + (n * 0.9999999999) * ray->direction.y,
			ray->origin.z + (n * 0.9999999999) * ray->direction.z
		};
		ft_normalize(&shadow.direction);
		if (determine_lighting(&shadow, app, hit_object) != -1)
			colour = scale_colour(hit_object->colour, hit_object, &shadow);
	}
	return (colour);
}
