/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 15:29:04 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static int	count_nb_sprites(char **map2d)
{
	int	x;
	int	y;
	int	nb_sprites;

	y = 0;
	nb_sprites = 0;
	while (map2d[y] != NULL)
	{
		x = 0;
		while (map2d[y][x] != 0)
		{
			if (ft_strchr("X", map2d[y][x]) != 0)
				(nb_sprites)++;
			x++;
		}
		y++;
	}
	return (nb_sprites);
}

static void	record_sprites_pos(t_params *game, int nb_sprites, char **map2d)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	game->sprites.pos_x = ft_calloc(nb_sprites, sizeof(int));
	game->sprites.pos_y = ft_calloc(nb_sprites, sizeof(int));
	if (game->sprites.pos_x == NULL || game->sprites.pos_y == NULL)
		exit_fct(game);
	while (map2d[++y] != NULL)
	{
		x = 0;
		while (map2d[y][x] != 0)
		{
			if (ft_strchr("X", map2d[y][x]) != 0 && i < nb_sprites)
			{
				game->sprites.pos_x[i] = x;
				game->sprites.pos_y[i] = y;
				i++;
			}
			x++;
		}
	}
}

t_bool	load_sprites(t_params *game)
{
	mlx_texture_t	*tmp[2];
	mlx_t			*mlx;

	mlx = game->win->window;
	tmp[0] = mlx_load_png("sprites/spaghettis_500x500.png");
	if (tmp[0])
	{
		game->sprites.img[0] = mlx_texture_to_image(mlx, tmp[0]);
		del_txt_tmp(tmp, 1);
	}
	else
	{
		del_txt_tmp(tmp, 1);
		return (FALSE);
	}
	game->sprites.nb_sprites = count_nb_sprites(game->map->map2d);
	game->sprites.nb_remaining = game->sprites.nb_sprites;
	record_sprites_pos(game, game->sprites.nb_sprites, game->map->map2d);
	return (TRUE);
}
