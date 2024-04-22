/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 17:05:01 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	display_welcome(mlx_t *mlx, t_params *game)
{
	char 		*str;
	char 		*str2;
	char 		*str3;

	str = ft_strdup("WELCOME TO PHILO 3D ");
	str2 = ft_strdup("FIND SPAGHETTIS BEFORE YOU DIE");
	str3 = ft_strdup("move to continue...");
	mlx_put_string(mlx, str, (int)(WIDTH / 2.5), 30);
	mlx_put_string(mlx, str2, (int)(WIDTH / 3), 60);
	mlx_put_string(mlx, str3, (int)(WIDTH / 2.5), 80);
	free (str);
	free (str2);
	free (str3);
	game->times.start_game = time_to_ms();
}

void	display_success(mlx_t *mlx, t_params *game)
{
	char 		*str;
	char 		*str2;
	char 		*str3;

	str = ft_strdup("CONGRATULATIONS");
	str2 = ft_strdup("YOU ATE ALL THE SPAGETTHIS OF THE MAP");
	str3 = ft_strdup("Go to bed now...");
	mlx_put_string(mlx, str, (int)(WIDTH / 2.5), 30);
	mlx_put_string(mlx, str2, (int)(WIDTH / 3), 60);
	mlx_put_string(mlx, str3, (int)(WIDTH / 2.5), 80);
	free (str);
	free (str2);
	free (str3);
	sleep(5);
	exit_fct(game);
}


void	display_all(t_params *game)
{
	if (raycasting(game, game->win, game->player) == FALSE)
		exit_fct(game);
	display_minimap(game);
	display_hands(game);
	display_infos(game);
}
