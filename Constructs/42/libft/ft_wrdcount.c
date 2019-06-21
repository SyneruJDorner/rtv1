/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:59:53 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 15:14:37 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wrdcount(char const *s, char c)
{
	int	i;
	int	ok;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		ok = 1;
		while (s[i] && s[i] == c)
		{
			ok = 0;
			i++;
		}
		while (s[i] && s[i] != c)
		{
			i++;
			ok = 1;
		}
		if (ok)
			count++;
	}
	return (count);
}
