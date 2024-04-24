/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:13 by aranger           #+#    #+#             */
/*   Updated: 2024/04/23 17:16:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static char	change_door_state(char c)
{
	if (c == 'P')
		return ('Q');
	return ('P');
}

void	manage_door(t_params *p)
{
	int	x;
	int	y;

	x = (int)p->player->pos_x;
	y = (int)p->player->pos_y;
	if (y - 1 >= 0 && ft_strchr("PQ", p->map->map2d[y - 1][x]) != 0)
		p->map->map2d[y - 1][x] = change_door_state(p->map->map2d[y - 1][x]);
	if (y + 1 < p->map->h_map && ft_strchr("PQ", p->map->map2d[y + 1][x]) != 0)
		p->map->map2d[y + 1][x] = change_door_state(p->map->map2d[y + 1][x]);
	if (x + 1 < p->map->w_map && ft_strchr("PQ", p->map->map2d[y][x + 1]) != 0)
		p->map->map2d[y][x + 1] = change_door_state(p->map->map2d[y][x + 1]);
	if (x -1 >= 0 && ft_strchr("PQ", p->map->map2d[y][x - 1]) != 0)
		p->map->map2d[y][x - 1] = change_door_state(p->map->map2d[y][x - 1]);
}
