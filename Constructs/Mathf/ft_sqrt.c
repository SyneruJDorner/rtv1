/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:43:42 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:04:10 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

float	ft_sqrt(float number)
{
	long		i;
	float		x;
	float		y;
	const float	threehalfs = 1.5f;

	x = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x * y * y));
	return (y);
}
