/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:20:30 by aranger           #+#    #+#             */
/*   Updated: 2024/04/17 16:21:24 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	print_player(t_params *p)
{
	mlx_image_t			*img;
	t_window_settings	*win;
	
	win = p->win;
	img = mlx_new_image(win->window, 50, 50);
	if (!img || (mlx_image_to_window(win->window, img, p->player->pos_x * 10, p->player->pos_y * 10) < 0))
		ft_error(win);
	display_square(0, 0, 10,img, convert_color(0xFF0000), FALSE);
	win->player_img = img;
}