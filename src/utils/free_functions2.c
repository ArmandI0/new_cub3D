/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/19 15:37:24 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_img_anim(t_params *game)
{
	if (game->anim_p[0] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[0]);
	if (game->anim_p[1] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[1]);
	if (game->anim_p[2] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[2]);
	if (game->anim_p[3] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[3]);
	if (game->anim_p[4] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[4]);
}

void	free_img_sprites(t_params *game)
{
	if (game->sprites.img[0] != NULL)
		mlx_delete_image(game->win->window, game->sprites.img[0]);
	if (game->sprites.img[1] != NULL)
		mlx_delete_image(game->win->window, game->sprites.img[1]);
	if (game->sprites.pos_x != NULL)
		free(game->sprites.pos_x);
	if (game->sprites.pos_y != NULL)
		free(game->sprites.pos_y);
}
