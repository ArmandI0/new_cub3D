/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/23 17:33:56 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	display_square(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= size)
	{
		while (y <= size)
		{
			put_pixel(img, start_x + x, start_y + y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	choose_color(t_coord p, int i, mlx_image_t *img)
{
	int j;

	j = 0;
	while (j < MINIMAP_SIZE)
	{
		if (((int)round(p.x) >= 0 && (int)round(p.x) < minimap->w_map) && ((int)round(p.y) >= 0 && (int)round(p.y) < minimap->h_map))
		{
		if (minimap->map2d[(int)round(y)][(int)round(x)] == '1')
			put_pixel(img, j, i, convert_color(0xA09C9C));
		else if (minimap->map2d[(int)round(y)][(int)round(x)] == '0')
			put_pixel(img, j, i, convert_color(0xFFFFFF));
		else if (ft_strchr("NSEW", minimap->map2d[(int)round(y)][(int)round(x)]) != 0)
			put_pixel(img, j, i, convert_color(0xFFFFFF));
		else if (ft_strchr("PQ", minimap->map2d[(int)round(y)][(int)round(x)]) != 0)
			put_pixel(img, j ,i, convert_color(0xFF0000));
		else
			put_pixel(img, j, i, convert_color(0xA09C9C));
		}		
		else
			put_pixel(img, j, i, convert_color(0xA09C9C));
		p.x = p.x + (1 / (double)MINIMAP_SIZE / 9);
		j++;
	}
}

void print_minimap(t_map *minimap, mlx_image_t *img, t_player *p)
{
	double	x;
	double	y;
	int		i;
	t_coord	pixel;
	i = 0;
	x = p->pos_x - 5;
	y = p->pos_y - 5;
	while (i < MINIMAP_SIZE)
	{
		pixel.x = x;
		pixel.y = y;
		y+= (1 / (double)MINIMAP_SIZE / 9);
		x = p->pos_x - 5;
		i++;
	}
	display_square((MINIMAP_SIZE / 2) - 2, (MINIMAP_SIZE / 2) - 2, 5, img, convert_color(0x000000));
}

void display_minimap(t_params *p)
{
	mlx_image_t	*img;

	img = p->win->minimap_img;
	p->win->minimap_img = mlx_new_image(p->win->window, 500, 500);
	print_minimap(p->map, p->win->minimap_img, p->player);
	mlx_delete_image(p->win->window, img);
	if (!p->win->minimap_img || (mlx_image_to_window(p->win->window, p->win->minimap_img, 10, 10) < 0))
		exit_fct(p);
	mlx_set_instance_depth(p->win->minimap_img->instances, 1);
}
