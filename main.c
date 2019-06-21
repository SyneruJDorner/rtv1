/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:56:31 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 12:29:23 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/rtv1.h"

#define KEY_BEGIN 2
#define KEY_END 3

#define EXPOSE 12
#define EXIT 17

int			expose_hook(t_mlx *mlx)
{
	return (0);
}

int			exit_hook(void)
{
	exit(0);
	return (0);
}

t_app		*setup_app(void)
{
	t_app	*app;

	if ((app = malloc(sizeof(t_app))) == NULL)
		return (NULL);
	init_mlx(&app->mlx, WIDTH, HEIGHT, "Raytracing");
	return (app);
}

int			main(int argc, char **argv)
{
	t_app	*app;

	if ((app = setup_app()) == NULL)
		return (-1);
	if ((app->reader.read_list = read_file("scene.env")) == NULL)
		return (-1);
	parse_list(app->reader.read_list, app);
	ft_lstfree(app->reader.read_list);
	raytracing(app);
	mlx_hook(app->mlx.window, KEY_BEGIN, 0, key_begin, &app->mlx);
	mlx_hook(app->mlx.window, KEY_END, 0, key_end, &app->mlx);
	mlx_hook(app->mlx.window, EXIT, 0, exit_hook, &app->mlx);
	mlx_hook(app->mlx.window, EXPOSE, 0, expose_hook, &app->mlx);
	mlx_loop(app->mlx.mlx);
	return (0);
}
