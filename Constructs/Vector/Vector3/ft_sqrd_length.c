/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrd_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:43:55 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:01:52 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../constructs.h"

float	ft_sqrd_length(t_vector3 vector)
{
	return (ft_sqr(vector.x) + ft_sqr(vector.y) + ft_sqr(vector.z));
}
