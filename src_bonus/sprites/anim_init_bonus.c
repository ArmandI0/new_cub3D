/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:06 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"


static t_bool	load_textures(t_params *game)
{
	game->texture[PARAM_NO] = mlx_load_png(game->path_texture[PARAM_NO]);
	game->texture[PARAM_SO] = mlx_load_png(game->path_texture[PARAM_SO]);
	game->texture[PARAM_EA] = mlx_load_png(game->path_texture[PARAM_EA]);
	game->texture[PARAM_WE] = mlx_load_png(game->path_texture[PARAM_WE]);
	if (!game->texture[PARAM_NO] || !game->texture[PARAM_EA]
		|| !game->texture[PARAM_SO] || !game->texture[PARAM_WE])
		return (FALSE);
	return (TRUE);
}

static void		put_anim_pattern(t_params *game)
{
	game->anim_p_pattern[0] = 8;
	game->anim_p_pattern[1] = 0;
	game->anim_p_pattern[2] = 1;
	game->anim_p_pattern[3] = 2;
	game->anim_p_pattern[4] = 3;
	game->anim_p_pattern[5] = 4;
	game->anim_p_pattern[6] = 3;
	game->anim_p_pattern[7] = 2;
	game->anim_p_pattern[8] = 1;
}

void	del_txt_tmp(mlx_texture_t **tmp, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (tmp[i])
			mlx_delete_texture(tmp[i]);
		i++;
	}
}

static t_bool	load_anim(t_params *game)
{
	mlx_texture_t	*tmp[5];
	mlx_t			*mlx;

	mlx = game->win->window;
	tmp[0] = mlx_load_png("sprites/player1.png");
	tmp[1] = mlx_load_png("sprites/player2.png");
	tmp[2] = mlx_load_png("sprites/player3.png");
	tmp[3] = mlx_load_png("sprites/player4.png");
	tmp[4] = mlx_load_png("sprites/player5.png");
	if (tmp[0] && tmp[1] && tmp[2] && tmp[3] && tmp[4])
	{
		game->anim_p[0] = mlx_texture_to_image(mlx, tmp[0]);
		game->anim_p[1] = mlx_texture_to_image(mlx, tmp[1]);
		game->anim_p[2] = mlx_texture_to_image(mlx, tmp[2]);
		game->anim_p[3] = mlx_texture_to_image(mlx, tmp[3]);
		game->anim_p[4] = mlx_texture_to_image(mlx, tmp[4]);
		put_anim_pattern(game);
		del_txt_tmp(tmp, 5);
	}
	else
	{
		del_txt_tmp(tmp, 5);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	load_images(t_params *game)
{
	if (load_textures(game) == FALSE)
		return (FALSE);
	if (load_anim(game) == FALSE)
		return (FALSE);
	if (load_sprites(game) == FALSE)
		return (FALSE);
	return (TRUE);
}
