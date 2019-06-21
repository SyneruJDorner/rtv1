/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:44:07 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 13:55:15 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../Constructs/constructs.h"
# include "../Intersections/intersections.h"

# define WIDTH 1280
# define HEIGHT 720

# define ANG tan(camera.fov * 0.5 * M_PI / 180)
# define ASPECTRATIO (double)WIDTH / (double)HEIGHT
# define INVH (1 / (double)HEIGHT)
# define INVW (1 / (double)WIDTH)

typedef struct		s_reader
{
	t_list			*read_list;
	char			*read_string;
}					t_reader;

typedef struct		s_app
{
	t_mlx			mlx;
	t_reader		reader;
	t_gameobject	*gameobjects;
	int				gameobjectcount;
	t_ray			ray;
}					t_app;

void				raytracing(t_app *app);
t_vector3			transform_rotation(t_matrix m, t_vector3 original);
t_vector3			transform_all(t_vector3 original, t_matrix m);
int					key_begin(int key, t_mlx *mlx);
int					key_end(int key, t_mlx *mlx);
void				parse_list(t_list *lst, t_app *app);
t_list				*read_file(char *path);
t_list				*read_to_list(char *path, t_list *readcontents);
t_list				*read_file_arg(int argc, char **argv);
t_list				*read_to_list_arg(int argc, char **argv,
					t_list *readcontents);
t_gameobject		*trace(t_ray *ray, t_app *app, double *n);
unsigned int		get_colour_hit(t_ray *ray, t_app *app);

#endif
