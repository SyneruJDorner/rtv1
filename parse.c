/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:07:58 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 12:52:12 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/rtv1.h"

t_objecttype		get_objecttype(t_list *lst)
{
	t_objecttype	object_type;

	if (ft_strstr(lst->content, "T_CAMERA"))
		object_type = T_CAMERA;
	if (ft_strstr(lst->content, "T_POINTLIGHT"))
		object_type = T_POINTLIGHT;
	else if (ft_strstr(lst->content, "T_PLANE"))
		object_type = T_PLANE;
	else if (ft_strstr(lst->content, "T_CUBE"))
		object_type = T_CUBE;
	else if (ft_strstr(lst->content, "T_SPHERE"))
		object_type = T_SPHERE;
	else if (ft_strstr(lst->content, "T_CONE"))
		object_type = T_CONE;
	else if (ft_strstr(lst->content, "T_CYLINDER"))
		object_type = T_CYLINDER;
	else if (ft_strstr(lst->content, "T_PYRAMID"))
		object_type = T_PYRAMID;
	return (object_type);
}

void				set_gameobject_info(t_gameobject *gameobject,
					char *lst_content)
{
	if (ft_strstr(lst_content, "position = "))
		gameobject->transform.position = str_to_vector3(lst_content);
	else if (ft_strstr(lst_content, "rotation = "))
		gameobject->transform.rotation = str_to_radian_rotation(lst_content);
	else if (ft_strstr(lst_content, "fov = "))
		gameobject->fov = str_get_value(lst_content);
	else if (ft_strstr(lst_content, "colour = "))
		gameobject->colour = str_get_hex(lst_content);
	else if (ft_strstr(lst_content, "width = "))
		gameobject->shape.width = str_get_value(lst_content);
	else if (ft_strstr(lst_content, "height = "))
		gameobject->shape.height = str_get_value(lst_content);
	else if (ft_strstr(lst_content, "depth = "))
		gameobject->shape.depth = str_get_value(lst_content);
	else if (ft_strstr(lst_content, "radius = "))
		gameobject->shape.radius = str_get_value(lst_content);
}

t_gameobject		get_objectinfo(t_list *lst)
{
	t_gameobject	gameobject;

	ft_rm_char(lst->content, ' ');
	gameobject.object_type = get_objecttype(lst);
	while (lst)
	{
		ft_rm_char(lst->content, ' ');
		if (ft_strstr(lst->content, "{"))
		{
			lst = lst->next;
			while (lst)
			{
				set_gameobject_info(&gameobject, lst->content);
				if (ft_strstr(lst->content, "}"))
				{
					lst = lst->next;
					return (gameobject);
				}
				lst = lst->next;
			}
		}
		lst = lst->next;
	}
	return (gameobject);
}

void				parse_list(t_list *lst, t_app *app)
{
	t_list			*tmp_lst;
	int				cnt;

	lst = ft_lst_ignorecomments(lst, "/*", "*/");
	tmp_lst = lst;
	ft_rm_char(lst->content, '\n');
	ft_rm_char(lst->content, ' ');
	cnt = 0;
	while (tmp_lst)
	{
		if (ft_strstr(tmp_lst->content, "OBJECT:"))
			cnt++;
		tmp_lst = tmp_lst->next;
	}
	app->gameobjectcount = cnt;
	app->gameobjects = (t_gameobject*)malloc(sizeof(t_gameobject) * (cnt));
	cnt = 0;
	while (lst)
	{
		if (ft_strstr(lst->content, "OBJECT:"))
			app->gameobjects[cnt++] = get_objectinfo(lst);
		lst = lst->next;
	}
	ft_lstfree(tmp_lst);
	app->gameobjectcount = cnt;
}
