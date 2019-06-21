/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:42:05 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 12:25:16 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/rtv1.h"

#define KEYRELEASED 0
#define KEYPRESSED 1

int	key_begin(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
		exit(1);
	return (0);
}

int	key_end(int key, t_mlx *mlx)
{
	return (0);
}
