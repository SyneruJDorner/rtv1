/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:56:07 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:57:50 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

typedef struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct		s_screen
{
	t_resolution	resolution;
	double			aspect_ratio;
}					t_screen;

#endif
