/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/19 18:36:32 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

t_bool	is_line_empty(t_list *last)
{
	int	i;

	i = 0;
	while ((last->content)[i] != '\n')
	{
		if ((last->content)[i] != ' ')
			return (FALSE);
		i++;
	}
	if ((last->content)[i + 1] != 0)
		return (FALSE);
	return (TRUE);
}

static void del_empty_lines_start(t_params *game)
{
	t_list  *tmp;
	t_list  *head;

	head = game->head_list_lines;
	while (head != NULL && is_line_empty(head) == TRUE)
	{
		tmp = head;
 		head = head->next;
		del_el_list(tmp, game);
	}
}

static void del_empty_lines_end(t_params *game)
{
	t_list  *last;
	t_list  *tmp;

	last = ft_lstlast(game->head_list_lines);
	while (last != NULL && is_line_empty(last) == TRUE)
	{
		tmp = last;
 		last = last->prev;
		del_el_list(tmp, game);
	}
}

static t_bool are_map_lines_valid(t_list *head)
{
	t_list  *element;
	int		i;

	i = 0;
	element = head;
	while (element)
	{
		i = 0;
		while (element->content[i] != 0)
		{
			if (ft_strchr("10 NSEWX\n", element->content[i]) == 0)
				return (FALSE);
			i++;
		}
 		element = element->next;
	}	
	return (TRUE);
}

t_errors	extract_map(t_params *game)
{
	del_empty_lines_start(game);
	del_empty_lines_end(game);
	if (are_map_lines_valid(game->head_list_lines) == FALSE)
		return (ER_INVALID_MAP_CHARACTER);
	return (0);
}
