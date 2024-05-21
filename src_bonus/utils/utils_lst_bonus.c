/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/05/21 21:20:25 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	del_el_list(t_list *element, t_params *game)
{
	if (element->prev == NULL && element->next != NULL)
	{
		game->head_list_lines = element->next;
		game->head_list_lines->prev = NULL;
	}
	else if (element->next == NULL && element->prev != NULL)
		element->prev->next = NULL;
	else if (element->prev != NULL && element->next != NULL)
	{
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	else
		game->head_list_lines = NULL;
	free_el_list(element);
}

void	put_line_to_nl(t_list *element, t_params *game)
{
	if (element != NULL && element->content != NULL)
	{
		free (element->content);
		element->content = NULL;
		element->content = ft_strdup("\n");
		if (element->content == NULL)
			print_err_free_exit(game, ER_DEFAULT);
	}
}
