/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/21 17:26:23 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	init_times_displays(t_params *game)
{
	game->times.spagh_eaten = ft_calloc(game->sprites.nb_sprites,
		sizeof(u_int64_t));
	if (game->times.spagh_eaten == NULL)
		exit_fct(game);
	game->times.start_game = time_to_ms();
	game->times.one_min = 0;
	game->times.dead = FALSE;
	game->times.time_given = 1000 * 60 * 2;
}

static void	display_sphagetti_eaten(t_sprites sprites, mlx_t *mlx, u_int64_t *time)
{
	char 		*str;
	int			y;
	int			i;

	i = 0;
	y = 50;
	while (i < sprites.nb_sprites)
	{
		if (time[i] > time_to_ms())
		{
			y += 30;
			str = ft_strdup("+1 SPAGHETTI");
			mlx_put_string(mlx, str, WIDTH / 3, y);
			free (str);
			if (y > HEIGHT - 50)
				y = 0;
		}
		i++;
	}
}

static void	display_time_given(mlx_t *mlx, t_display times, t_params *game)
{
	char 		*str;
	int 		min;
	int 		sec;
	u_int64_t	remaining_time;

	remaining_time = time_to_ms() - times.start_game;
	min = (remaining_time / 1000) / 60;
	sec = (remaining_time / 1000) % 60;
	if (remaining_time < times.time_given)
	{
		str = ft_strdup("REMAINING TIME : ");
		str = ft_fstrjoin(str, ft_itoa(min));
		str = ft_fstrjoin(str, ft_strdup(" min "));
		str = ft_fstrjoin(str, ft_itoa(sec));
		str = ft_fstrjoin(str, ft_strdup(" sec"));
		mlx_put_string(mlx, str, WIDTH / 3, 30);
		free (str);
	}
	else
		game->times.dead = TRUE;
}

static void	display_dead(mlx_t *mlx)
{
	char 		*str;

	str = ft_strdup("SORRY DUDE, YOU STARVED");
	mlx_put_string(mlx, str, WIDTH / 3, 50);
	free (str);
}

void	display_infos(t_params *game)
{
	display_sphagetti_eaten(game->sprites, game->win->window, game->times.spagh_eaten);
	if (game->times.dead == FALSE)
		display_time_given(game->win->window, game->times, game);
	else
	{
		display_dead(game->win->window);
		sleep(10);
		exit_fct(game);
	}
}
