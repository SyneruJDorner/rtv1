/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 07:00:46 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:06:06 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitcount(char const *s, char c, int i)
{
	size_t tmp;

	tmp = 0;
	while (s[i] && s[i] != c)
	{
		tmp++;
		i++;
	}
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	len = ft_wrdcount(s, c);
	if (!(str = (char**)malloc(sizeof(*str) * (len))))
		return (NULL);
	i = 0;
	while (len > 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		str[j] = ft_strsub(s, i, ft_splitcount(s, c, i));
		j++;
		i = i + ft_splitcount(s, c, i);
		len--;
	}
	str[j] = 0;
	return (str);
}
