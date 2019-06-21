/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:51:31 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:09:13 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nbr;
	char	neg;

	while ((*str < 48 || *str > 57) && *str != 45)
		str++;
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	while (ft_isdigit(*str))
	{
		while (*str < 48 || *str > 57)
			break ;
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg ? -nbr : nbr);
}
