/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:12:43 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:37:37 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

void	init_mlx(t_mlx *mlx, int width, int height, char *title)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, width, height, title);
	initimage(mlx, width, height);
}

void	initimage(t_mlx *mlx, int width, int height)
{
	t_image	*img;

	if ((img = (t_image *)malloc(sizeof(t_image))) == NULL)
		return ;
	img->img = mlx_new_image(mlx->mlx, width, height);
	img->data = mlx_get_data_addr(img->img,
								&img->bpp,
								&img->sizeline,
								&img->endian);
	img->bpp /= 8;
	mlx->image = img;
}

void	putpixelimage(t_image *image, int width, int coord[2], int colour)
{
	*(int *)(image->data + ((coord[0] + coord[1]
					* width) * image->bpp)) = colour;
}
