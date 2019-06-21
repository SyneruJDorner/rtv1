/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:41:48 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:14:24 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst)
{
	t_list	*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst != NULL)
	{
		ft_putstr(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
	ft_lstfree(tmp_lst);
}
