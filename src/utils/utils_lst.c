/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/29 19:50:56 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
