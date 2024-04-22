/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:43:06 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 11:53:12 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static t_player	*set_orientation(double dir_x, double dir_y,
				double plane_x , double plane_y)
{
	t_player	*new_player;

	new_player = malloc(sizeof(t_player));
	if (new_player == NULL)
		return (NULL);
	new_player->dir_x = dir_x;
	new_player->dir_y = dir_y;
	new_player->plane_x = plane_x;
	new_player->plane_y = plane_y;
	return (new_player);
}

t_player	*init_new_players(t_param_type direction, double x, double y)
{
	t_player	*new_player;

	new_player = NULL;
	if (direction == PARAM_NO)
		new_player = set_orientation(0, -1, 0.66, 0);
	else if (direction == PARAM_SO)
		new_player = set_orientation(0, 1, -0.66, 0);
	else if (direction == PARAM_WE)
		new_player = set_orientation(-1, 0, 0, -0.66);
	else if (direction == PARAM_EA)
		new_player = set_orientation(1, 0, 0, 0.66);
	if (new_player != NULL)
	{
		new_player->pos_x = x;
		new_player->pos_y = y;
	}
	return (new_player);
}


