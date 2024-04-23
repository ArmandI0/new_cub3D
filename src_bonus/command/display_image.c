/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:30:31 by aranger           #+#    #+#             */
/*   Updated: 2024/04/23 14:36:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	display_game(void *params)
{
	t_params	*game;
	static size_t	start_time = 0;
	size_t			time;

	game = params;
	time = get_current_time();
	if (start_time == 0)
		start_time = get_current_time();
	if (time - start_time < 33)
		return ;
	else
	{
		start_time = get_current_time();
		display_minimap(game);
		if (raycasting(game, game->win, game->player) == FALSE)
			exit_fct(game);
		//display_infos(game);
	}
}