/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:44:07 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:00:12 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

float	ft_length(t_vector3 vector)
{
	return (sqrt(ft_sqr(vector.x) + ft_sqr(vector.y) + ft_sqr(vector.z)));
}
