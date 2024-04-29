/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:49:25 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:50:56 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	find_wall(t_params *game, t_var_raycasting *var)
{
	int	side;
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->dt_x;
			var->pos_x += var->step_x;
			side = EAST_WEST;
		}
		else
		{
			var->side_dist_y += var->dt_y;
			var->pos_y += var->step_y;
			side = NORTH_SOUTH;
		}
		if (ft_strchr("1P", game->map->map2d[var->pos_y][var->pos_x]) != 0)
			hit = 1;
	}
	return (side);
}

void	get_side_put_perp_dist(t_var_raycasting *var, t_params *game)
{
	var->side = find_wall(game, var);
	if (var->side == EAST_WEST)
		var->perp_dist = (var->side_dist_x - var->dt_x);
	else
		var->perp_dist = (var->side_dist_y - var->dt_y);
}
