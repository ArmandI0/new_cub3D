/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:49:25 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 15:06:47 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_param_type	choose_texture(t_player *player,
	t_var_raycasting *var, int side)
{
	if (player->pos_x > var->pos_x && side == EAST_WEST)
		return(PARAM_EA);
	else if (player->pos_x < var->pos_x && side == EAST_WEST)
		return(PARAM_WE);
	else if (player->pos_y > var->pos_y && side == NORTH_SOUTH)
		return(PARAM_SO);
	else if (player->pos_y < var->pos_y && side == NORTH_SOUTH)
		return(PARAM_NO);
	else
		return(PARAM_NO);
}

static int	get_x_on_texture(t_var_raycasting *var, uint32_t width, int side, t_player *p)
{
 	double	wall_x;
	int		x_txt;

	(void)p;
	if (side == EAST_WEST)
		wall_x = (double)p->pos_y + var->perp_dist * var->ray_dir_y;
	else
		wall_x = (double)p->pos_x + var->perp_dist * var->ray_dir_x;
	wall_x -= floor((wall_x));
	x_txt = (int)(wall_x * (double)width);
	if((side == EAST_WEST && var->ray_dir_x > 0)
		|| (side == NORTH_SOUTH && var->ray_dir_y < 0))
		x_txt = width - x_txt - 1; 
	return (x_txt);
}

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

t_bool	load_images(t_params *game)
{
	if (load_textures(game) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	draw_ver_line(t_params *game, t_var_raycasting *var, int x_position,  int side)
{
	int				color;
	int				y;
	t_param_type	dir_txt;
	double			ratio;
	int				x_txt;

	dir_txt = choose_texture(game->player, var, side);
	x_txt = get_x_on_texture(var, game->texture[dir_txt]->width, side, game->player);
	ratio = (double)(var->end - var->start) / game->texture[dir_txt]->height;
	y = 0;
	while (y < HEIGHT)
	{
		if (y <  var->start)
			color = game->ceiling_color;
		else if (y >= var->end)
			color = game->floor_color;
		else
			color = get_color_px_txt(x_txt, ((double)(y - var->start) / ratio), game->texture[dir_txt]);
		mlx_put_pixel(game->win->img, x_position, y, color);
		y++;
	}
}
