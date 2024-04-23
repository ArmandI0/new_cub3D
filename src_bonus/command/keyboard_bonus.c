/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:12:00 by aranger           #+#    #+#             */
/*   Updated: 2024/04/23 17:12:43 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	rotation(t_params *p, double step)
{
	rotate_player(p->player, step);
}

static void	translation(t_params *p, double step, t_bool tr)
{
	if (tr == FALSE)
		translate_player_forward(p->player, step, p->map->map2d);
	else
		translate_player_l_to_r(p->player, step, p->map->map2d);
	remove_sprite_collision(p->player, p->sprites, p);
	display_hands(p);
}

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		translation(p, SPEED, FALSE);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		translation(p, -SPEED, FALSE);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		translation(p, SPEED, TRUE);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		translation(p, -SPEED, TRUE);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		rotation(p, SENSIVITY);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		rotation(p, -SENSIVITY);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_P)
		printf("pos x : %f\npos y : %f\n", p->player->pos_x, p->player->pos_y);
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		manage_door(p);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(p->win->window);
	}
	translation_key(keydata, param);
}
