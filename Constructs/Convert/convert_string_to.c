/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:15:03 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:37:30 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constructs.h"

t_vector3		str_to_vector3(char *str)
{
	t_vector3	vector;
	char		**vector_arr;
	int			count;

	vector_arr = NULL;
	vector = set_vector3_identity();
	ft_rm_char(str, '\n');
	if ((str = ft_strrchr(str++, '(')) != NULL)
	{
		count = ft_wrdcount(str, ' ');
		vector_arr = ft_strsplit(str, ' ');
		vector.x = ft_atoi(vector_arr[0]);
		vector.y = ft_atoi(vector_arr[1]);
		vector.z = ft_atoi(vector_arr[2]);
		while (count + 1 > 0)
			free(vector_arr[count--]);
		free(vector_arr);
	}
	return (vector);
}

t_vector3		str_to_radian_rotation(char *str)
{
	t_vector3	vector;
	char		**vector_arr;
	int			i;
	int			count;

	i = -1;
	vector = set_vector3_identity();
	ft_rm_char(str, '\n');
	if ((str = ft_strrchr(str++, '(')) != NULL)
	{
		count = ft_wrdcount(str, ' ');
		vector_arr = ft_strsplit(str, ' ');
		vector.x = (M_PI / 180) * ft_atoi(vector_arr[0]);
		vector.y = (M_PI / 180) * ft_atoi(vector_arr[1]);
		vector.z = (M_PI / 180) * ft_atoi(vector_arr[2]);
		while (count + 1 > 0)
			free(vector_arr[count--]);
		free(vector_arr);
	}
	return (vector);
}

double			str_get_value(char *str)
{
	double	value;

	value = 0;
	ft_rm_char(str, '\n');
	if ((str = ft_strrchr(str, '=')) != NULL)
	{
		str = ft_strrchr(str, '=');
		value = ft_atoi(str);
	}
	return (value);
}

unsigned int	hex_string_to_int(char const *hexstring)
{
	unsigned int	result;
	char const		*str;
	unsigned int	add;
	char			c;

	result = 0;
	str = hexstring;
	while (*str)
	{
		c = *str;
		result <<= 4;
		if (c >= '0' && c <= '9')
			add = c - '0';
		else if (c >= 'A' && c <= 'F')
			add = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			add = c - 'a' + 10;
		else
			return (0x000000);
		result += add;
		++str;
	}
	return (result);
}

unsigned int	str_get_hex(char *str)
{
	unsigned int	colour_hex;

	colour_hex = 0x000000;
	ft_rm_char(str, '\n');
	if ((str = ft_strrchr(str, 'x')) != NULL)
	{
		ft_rm_char(str, 'x');
		ft_rm_char(str, ';');
		colour_hex = hex_string_to_int(str);
	}
	return (colour_hex);
}
