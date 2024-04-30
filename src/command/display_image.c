/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:30:31 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:52:48 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_move(t_params *game)
{
	if (game->w_key == TRUE)
		translation(game, SPEED, FALSE);
	if (game->s_key == TRUE)
		translation(game, -SPEED, FALSE);
	if (game->a_key == TRUE)
		translation(game, -SPEED, TRUE);
	if (game->d_key == TRUE)
		translation(game, SPEED, TRUE);
	if (game->left_key == TRUE)
		rotation(game, -SENSIVITY);
	if (game->right_key == TRUE)
		rotation(game, SENSIVITY);
}

void	move_player(void *params)
{
	t_params		*game;
	static size_t	start_time = 0;
	size_t			time;

	game = params;
	time = get_current_time();
	if (start_time == 0)
		start_time = get_current_time();
	if (time - start_time < 20)
		return ;
	else
	{
		start_time = get_current_time();
		set_move(game);
	}
}

void	display_game(void *params)
{
	t_params		*game;
	static size_t	start_time = 0;
	size_t			time;

	game = params;
	time = get_current_time();
	if (start_time == 0)
		start_time = get_current_time();
	if (time - start_time < 20)
		return ;
	else
	{
		start_time = get_current_time();
		if (raycasting(game, game->win, game->player) == FALSE)
			print_err_free_exit(game, ER_DEFAULT);
	}
}
