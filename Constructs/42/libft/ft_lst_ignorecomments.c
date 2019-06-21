/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ignorecomments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:08:26 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 14:11:35 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_ignorecomments(t_list *lst,
		char *start_comment, char *end_comment)
{
	int	lst_pos;

	lst_pos = -1;
	ft_rm_char(lst->content, '\n');
	if (ft_strequ(lst->content, start_comment) == TRUE)
	{
		while (lst)
		{
			ft_rm_char(lst->content, '\n');
			if (ft_strequ(lst->content, end_comment) == TRUE)
			{
				ft_rm_char(lst->content, '\n');
				if (lst->next != NULL)
					lst = lst->next;
				break ;
			}
			if (lst->next == NULL)
				break ;
			lst = lst->next;
		}
	}
	return (lst);
}
