/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/25 22:09:23 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	display_start(t_params *game)
{
	mlx_image_t	*img1;
	mlx_image_t	*img2;

	img1 = game->texts[0];
	img2 = game->texts[1];
	if (get_current_time() < (game->time_start + 1000 * 5))
	{
		mlx_image_to_window(game->win->window, img1, WIDTH / 2 - img1->width / 2, 30);
		mlx_set_instance_depth(img1->instances, 2);
		mlx_image_to_window(game->win->window, img2, WIDTH / 2 - img2->width / 2, 90);
		mlx_set_instance_depth(img2->instances, 3);
		img1->enabled = TRUE;
		img2->enabled = TRUE;		
	}
	else
	{
		img1->enabled = FALSE;
		img2->enabled = FALSE;
	}
}

static void	display_end(t_params *game, mlx_t *win)
{
	mlx_image_t	*img1;
	mlx_image_t	*img2;
	mlx_image_t	*img3;

	img1 = game->texts[2];
	img2 = game->texts[3];
	img3 = game->texts[4];
	if (game->sprites.nb_remaining == 0)
	{
		mlx_image_to_window(win, img1, WIDTH / 2 - img1->width / 2, 30);
		mlx_set_instance_depth(img1->instances, 2);
		mlx_image_to_window(win, img2, WIDTH / 2 - img2->width / 2, 90);
		mlx_set_instance_depth(img2->instances, 3);
		mlx_image_to_window(win, img3, WIDTH / 2 - img3->width / 2, 150);
		mlx_set_instance_depth(img3->instances, 3);
		img1->enabled = TRUE;
		img2->enabled = TRUE;
		img3->enabled = TRUE;
	}
	else
	{
		img1->enabled = FALSE;
		img2->enabled = FALSE;
		img3->enabled = FALSE;
	}
}

void	display_infos(t_params *game)
{
	(void)game;
	display_start(game);
	display_end(game, game->win->window);
}
