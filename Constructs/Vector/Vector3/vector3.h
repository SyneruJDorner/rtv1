/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:11:17 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:12:08 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef struct		s_ray
{
	t_vector3		origin;
	t_vector3		direction;
}					t_ray;

t_vector3			set_vector3_identity();
void				set_vector3(float x, float y, float z, t_vector3 *ret);
t_vector3			copy_vector3(t_vector3 vector_to_copy);
void				ft_normalize(t_vector3 *vector3);
float				ft_sqrd_length(t_vector3 vector);
float				ft_length(t_vector3 vector);
float				ft_magnitude(t_vector3 v1, t_vector3 v2);
double				ft_dot(t_vector3 v1, t_vector3 v2);
t_vector3			ft_cross(t_vector3 v1, t_vector3 v2, t_vector3 vector);
float				vector_points_to_distance(t_vector3 v1, t_vector3 v2);
void				vector3_add_float(t_vector3 v1, float value,
					t_vector3 *ret);
void				vector3_add_vector3(t_vector3 v1, t_vector3 v2,
					t_vector3 *ret);
void				vector3_minus_vector3(t_vector3 v1, t_vector3 v2,
					t_vector3 *ret);
double				vector3_multiply_vector3(t_vector3 v1, t_vector3 v2,
					double ret);
void				vector3_multiply_float(t_vector3 v1, double value,
					t_vector3 *ret);
void				vector3_divide_vector3(t_vector3 v1, t_vector3 v2,
					t_vector3 ret);
void				vector3_divide_float(t_vector3 v1, float value,
					t_vector3 *ret);

#endif
