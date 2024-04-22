/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/09 14:23:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_list	*line_to_list(const char *line, t_list *last_el)
{
	t_list	*new_el;

	new_el = NULL;
	if (line != NULL && last_el == NULL)
	{
		last_el = ft_lstnew(ft_strdup(line));
		return (last_el);
	}
	else if (line != NULL && last_el != NULL)
	{
		new_el = ft_lstnew(ft_strdup(line));
		last_el->next = new_el;
		new_el->prev = last_el;
	}
	return (new_el);
}

int	extract_file_into_list(t_params *game, const char *filepath)
{
	int		fd;
	char	*line;
	t_list	*last_el_list;

	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	game->head_list_lines = line_to_list((const char *)line,
			game->head_list_lines);
	last_el_list = game->head_list_lines;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		last_el_list = line_to_list((const char *)line, last_el_list);
		if (line != NULL && last_el_list == NULL)
		{
			close (fd);
			free (line);
			return (ER_EXTRACTION_MAP);
		}
	}
	free(line);
	close(fd);
	return (0);
}
