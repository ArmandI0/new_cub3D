/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/29 19:50:56 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	display_start(t_params *game)
{
	mlx_image_t	*img1;
	mlx_image_t	*img2;

	img1 = game->texts[0];
	img2 = game->texts[1];
	if (get_current_time() < (game->time_start + 1000 * 5))
	{
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
	mlx_image_t	*img[3];

	img[0] = game->texts[2];
	img[1] = game->texts[3];
	img[2] = game->texts[4];
	if (game->time_end == 0 && game->sprites.nb_remaining == 0)
		game->time_end = get_current_time();
	if (game->sprites.nb_remaining == 0
		&& (get_current_time() - game->time_end) < 3000)
	{
		img[0]->enabled = TRUE;
		img[1]->enabled = TRUE;
		img[2]->enabled = TRUE;
	}
	else if ((get_current_time() - game->time_end) > 5000
		&& game->sprites.nb_remaining == 0)
	{
		free_game(game);
		exit (EXIT_SUCCESS);
	}
	else
		return ;
}

void	display_infos(t_params *game)
{
	display_start(game);
	display_end(game);
}
