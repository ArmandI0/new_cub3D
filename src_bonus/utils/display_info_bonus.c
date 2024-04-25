/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/25 22:00:53 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	display_start(t_params *game)
{
	mlx_image_t	*img1;
	mlx_image_t	*img2;

	img1 = game->texts[0];
	img2 = game->texts[1];
		printf("%ld\n", game->time_start);
	if (get_current_time() < game->time_start + 1000 * 1000 * 5)
	{
		mlx_image_to_window(game->win->window, img1, WIDTH / 2 - img1->width / 2, 30);
		mlx_set_instance_depth(img1->instances, 2);
		mlx_image_to_window(game->win->window, img2, WIDTH / 2 - img2->width / 2, 70);
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

static void	display_end(t_params *game)
{
	mlx_image_t	*img1;
	mlx_image_t	*img2;

	img1 = game->texts[2];
	img2 = game->texts[3];
	if (game->sprites.nb_remaining == 0)
	{
		mlx_image_to_window(game->win->window, img1, WIDTH / 2 - img1->width / 2, 30);
		mlx_set_instance_depth(img1->instances, 2);
		mlx_image_to_window(game->win->window, img2, WIDTH / 2 - img2->width / 2, 70);
		mlx_set_instance_depth(img2->instances, 3);		
	}
	else
	{
		img1->enabled = FALSE;
		img2->enabled = FALSE;
	}
}

void	display_infos(t_params *game)
{
	(void)game;
	display_start(game);
	display_end(game);
}
