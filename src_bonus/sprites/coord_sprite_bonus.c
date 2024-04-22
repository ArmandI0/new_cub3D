/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 16:16:11 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	get_pos_horiz_sprite(t_coord_sprite_screen *s, t_coord sprite_matrix)
{
	s->x_middle = (WIDTH / 2) * (1 + sprite_matrix.x / sprite_matrix.y);
	s->w = (int)(HEIGHT / (sprite_matrix.y));
	if (s->w < 0)
		s->w = - s->w;
	s->x_start = (int)(s->x_middle - (s->w / 2));
	s->x_end = (int)(s->x_middle + (s->w / 2));
}

void	get_pos_vert_sprite(t_coord_sprite_screen *s, t_coord sprite_matrix)
{
	s->h = (int)(HEIGHT / (sprite_matrix.y));
	if (s->h < 0)
		s->h = - s->h;
	s->y_start = HEIGHT / 2 - (int)(s->h / 2);
	if (s->y_start < 0)
		s->y_start = 0;
	s->y_end = HEIGHT / 2 + (int)(s->h / 2);
	if (s->y_end >= HEIGHT)
		s->y_end = HEIGHT - 1;
}

t_coord	get_pos_sprite_transformed(int i, t_player *p, t_sprites sprites,
	int *sprite_order)
{
	double	relative_x;
	double	relative_y;
	double	inv_det;
	t_coord	sprite_matrix;

	relative_x = (sprites.pos_x[sprite_order[i]] + 0.5) - (p->pos_x);
	relative_y = (sprites.pos_y[sprite_order[i]] + 0.5)- (p->pos_y);
	inv_det = 1.0 / (p->plane_x * p->dir_y - p->dir_x * p->plane_y);
	sprite_matrix.x = inv_det * (p->dir_y * relative_x - p->dir_x * relative_y);
	sprite_matrix.y = inv_det * (-p->plane_y * relative_x + p->plane_x * relative_y);
	return (sprite_matrix);
}
