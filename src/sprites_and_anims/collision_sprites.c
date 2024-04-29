/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:50:56 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	remove_sprite_collision(t_player *p, t_sprites sprites, t_params *game)
{
	int	i;

	i = 0;
	while (i < sprites.nb_sprites)
	{
		if (sprites.pos_x[i] == (int)(p->pos_x)
			&& sprites.pos_y[i] == (int)(p->pos_y))
		{
			sprites.pos_x[i] = -1;
			sprites.pos_y[i] = -1;
			(game->sprites.nb_remaining)--;
		}
		i++;
	}
}
