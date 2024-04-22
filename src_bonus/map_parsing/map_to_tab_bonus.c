/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/09 14:48:08 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static int	get_nb_lines(t_list *head)
{
	int		nb_lines;
	t_list  *tmp;

	tmp = head;
	nb_lines = 0;
	while (tmp)
	{
		if (tmp->content != NULL)
			nb_lines++;
		tmp = tmp->next;
	}
	return (nb_lines);
}

static int	get_len_max(t_list *head)
{
	int		len_max;
	int		len_line;
	t_list  *tmp;

	tmp = head;
	len_line = 0;
	len_max = 0;
	while (tmp)
	{
		if (tmp->content != NULL)
		{
			len_line = ft_strlen(tmp->content);
			if ((tmp->content)[len_line - 1] == '\n')
				len_line -= 1;
			if (len_line > len_max)
				len_max = len_line;
		}
		tmp = tmp->next;
	}
	return (len_max);
}

static t_bool	line_to_tab(char **map, t_list *line, int id_line, int sizemax)
{
	char	*endline;

	map[id_line] = ft_calloc(sizemax + 1, sizeof(char));
	if (map[id_line] == NULL)
		return (FALSE);
	ft_memset(map[id_line], ' ', sizemax);
	ft_strlcpy(map[id_line], line->content, sizemax + 1);
	if ((int)ft_strlen(line->content) < sizemax)
		*(ft_strchr(map[id_line], '\0')) = ' ';
	endline = ft_strchr(map[id_line], '\n');
	if (endline)
		*endline = ' ';
	return (TRUE);
}

t_bool	map_to_tab(t_params *game, t_list *head)
{
	t_list	*line;
	int		size_max_line;
	int		nb_lines;
	int		id_line;
	
	id_line = 0;
	line = head;
	nb_lines = get_nb_lines(head);
	size_max_line = get_len_max(head);
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
		return (FALSE);
	game->map->map2d = ft_calloc(nb_lines + 1, sizeof(char *));
	if (game->map->map2d == NULL)
		return (FALSE);
	while (line)
	{
		if (line_to_tab(game->map->map2d, line, id_line, size_max_line) == FALSE)
			return (FALSE);
		id_line ++;
		line = line->next;
	}
	game->nb_map_lines = nb_lines;
	return (TRUE);
}
