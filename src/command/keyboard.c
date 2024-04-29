/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:12:00 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:58:41 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotation(t_params *p, double step)
{
	rotate_player(p->player, step);
}

void	translation(t_params *p, double step, t_bool tr)
{
	if (tr == FALSE)
		translate_player_forward(p->player, step, p->map->map2d);
	else
		translate_player_l_to_r(p->player, step, p->map->map2d);
}

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		p->w_key = TRUE;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		p->w_key = FALSE;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p->s_key = TRUE;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		p->s_key = FALSE;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p->d_key = TRUE;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		p->d_key = FALSE;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p->a_key = TRUE;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		p->a_key = FALSE;
}

static void	rotation_key(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		p->right_key = TRUE;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		p->right_key = FALSE;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		p->left_key = TRUE;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		p->left_key = FALSE;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(p->win->window);
	}
	translation_key(keydata, param);
	rotation_key(keydata, param);
}
