/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_hands_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 18:38:18 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	loop_put_img_anim(t_params *game, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(game->win->window, img, x, y);
	mlx_set_instance_depth(img->instances, 1);
	img->enabled = FALSE;
}

void	init_display_anims(t_params *game)
{
	int			i;
	int			x;
	int			y;
	mlx_image_t	*img;

	i = 0;
	while (i < 5)
	{
		img = game->anim_p[i];
		y = HEIGHT - img->height;
		x = (WIDTH - img->width) / 2;
		loop_put_img_anim(game, img, x, y);
		img = game->texts[i];
		y = 20 + i * 80;
		x = (WIDTH - img->width) / 2;
		loop_put_img_anim(game, img, x, y);
		i++;
	}
}

void	display_hands(t_params *game)
{
	static int	frame = 1;
	int			tot_frames;
	mlx_image_t	*img;

	game->anim_p[0]->enabled = FALSE;
	game->anim_p[1]->enabled = FALSE;
	game->anim_p[2]->enabled = FALSE;
	game->anim_p[3]->enabled = FALSE;
	game->anim_p[4]->enabled = FALSE;
	img = game->anim_p[game->anim_p_pattern[frame]];
	tot_frames = game->anim_p_pattern[0];
	img->enabled = TRUE;
	frame++;
	if (frame > tot_frames)
		frame = 1;
}
