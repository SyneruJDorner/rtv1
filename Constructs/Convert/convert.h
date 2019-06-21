/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:14:49 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:50:03 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

t_vector3		str_to_vector3(char *str);
t_vector3		str_to_radian_rotation(char *str);
double			str_get_value(char *str);
unsigned int	str_get_hex(char *str);

#endif
