/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 06:42:41 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/25 12:52:57 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/rtv1.h"

t_list	*read_to_list_arg(int argc, char **argv, t_list *readcontents)
{
	int		fd;
	char	*line;

	readcontents = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			line = NULL;
			while ((get_next_line(fd, &line)) > 0)
			{
				ft_strcat(line, "\n");
				ft_lstadd(&readcontents, ft_lstnew(line, ft_strlen(line) + 1));
				ft_strdel(&line);
			}
		}
	}
	if (readcontents != NULL)
		close(fd);
	return (readcontents);
}

t_list	*read_file_arg(int argc, char **argv)
{
	t_list		*readcontents;

	if (!(readcontents = read_to_list_arg(argc, argv, readcontents)))
		return (NULL);
	return (readcontents);
}

t_list	*read_to_list(char *path, t_list *readcontents)
{
	int		fd;
	char	*line;

	readcontents = NULL;
	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		line = NULL;
		while ((get_next_line(fd, &line)) > 0)
		{
			ft_strcat(line, "\n");
			ft_lstadd(&readcontents, ft_lstnew(line, ft_strlen(line) + 1));
			ft_strdel(&line);
		}
	}
	ft_lstrev(&readcontents);
	if (readcontents != NULL)
		close(fd);
	return (readcontents);
}

t_list	*read_file(char *path)
{
	t_list		*readcontents;

	if (!(readcontents = read_to_list(path, readcontents)))
		return (NULL);
	return (readcontents);
}
