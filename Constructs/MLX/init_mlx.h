/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:35:12 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 16:23:57 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX_H
# define INIT_MLX_H

# include <mlx.h>

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	t_image			*image;
	t_camera		camera;
}					t_mlx;

void				init_mlx(t_mlx *mlx, int width, int height,
					char *title);
void				putpixelimage(t_image *image, int width, int corrd[2],
					int colour);
void				initimage(t_mlx *mlx, int width, int height);

#endif
