/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_hands_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/23 14:10:41 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	display_hands(t_params *game)
{
	static int	frame = 1;
	int			tot_frames;
	mlx_image_t *img;
	int			x;
	int			y;

	game->anim_p[0]->enabled = FALSE;
	game->anim_p[1]->enabled = FALSE;
	game->anim_p[2]->enabled = FALSE;
	game->anim_p[3]->enabled = FALSE;
	game->anim_p[4]->enabled = FALSE;
	img = game->anim_p[game->anim_p_pattern[frame]];
	tot_frames = game->anim_p_pattern[0];
	y = HEIGHT - img->height;
	x = (WIDTH - img->width) / 2;
	mlx_image_to_window(game->win->window, img, x, y);
	mlx_set_instance_depth(img->instances, 1);
	img->enabled = TRUE;
	frame++;
	if (frame > tot_frames)
		frame = 1;
}
