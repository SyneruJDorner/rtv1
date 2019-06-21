/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:07:13 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:40:47 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

typedef struct	s_tansform
{
	t_vector3	position;
	t_vector3	rotation;
	t_matrix	to_world;
	t_matrix	to_local;
}				t_transform;

t_vector3		transform_rotation(t_matrix m, t_vector3 original);
t_vector3		transform_all(t_vector3 original, t_matrix m);

#endif
