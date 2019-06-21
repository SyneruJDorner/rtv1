/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:21:21 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:16:50 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rm_char(char *dest, char c)
{
	int		removed;
	char	*tmp;
	size_t	len;

	removed = 0;
	while (*dest)
	{
		tmp = strchr(dest, c);
		if (NULL == tmp)
			break ;
		len = strlen(tmp + 1);
		memmove(tmp, tmp + 1, len);
		tmp[len] = 0;
		++removed;
		dest = tmp;
	}
	return (removed);
}
