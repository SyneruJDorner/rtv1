/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameobject.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:43:40 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:49:05 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

typedef struct		s_camera
{
	t_transform		transform;
	int				move[4];
	float			speed;
}					t_camera;

typedef enum		e_objecttype
{
	T_CAMERA = -2,
	T_POINTLIGHT = -1,
	T_PLANE = 0,
	T_CUBE = 1,
	T_SPHERE = 2,
	T_CONE = 3,
	T_CYLINDER = 4,
	T_PYRAMID = 5,
}					t_objecttype;

typedef struct		s_shape
{
	double			width;
	double			height;
	double			depth;
	double			radius;
}					t_shape;

typedef struct		s_gameobject
{
	int				object_type;
	t_transform		transform;
	t_shape			shape;
	double			fov;
	unsigned int	colour;
	t_vector3		hit;
	t_vector3		normal;
}					t_gameobject;

#endif
