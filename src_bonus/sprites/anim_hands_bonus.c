/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_hands_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:06 by aranger          ###   ########.fr       */
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

	img = game->anim_p[game->anim_p_pattern[frame]];
	tot_frames = game->anim_p_pattern[0];
	y = HEIGHT - img->height;
	x = (WIDTH - img->width) / 2;
	mlx_image_to_window(game->win->window, img, x, y);
	frame++;
	if (frame > tot_frames)
		frame = 1;
}
