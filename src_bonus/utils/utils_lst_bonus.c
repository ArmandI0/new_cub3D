/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:08 by aranger          ###   ########.fr       */
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
