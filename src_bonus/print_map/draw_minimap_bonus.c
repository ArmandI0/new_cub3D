/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:39:00 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	display_square(int size, mlx_image_t *img, uint32_t color)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;	

	x = 0;
	y = 0;
	start_x = (MINIMAP_SIZE / 2) - 2;
	start_y = (MINIMAP_SIZE / 2) - 2;
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

static void	put_px_minimap(char map2d_char, mlx_image_t *img, int j, int i)
{
	if (map2d_char == '1')
		put_pixel(img, j, i, convert_color(0xA09C9C));
	else if (map2d_char == '0')
		put_pixel(img, j, i, convert_color(0xFFFFFF));
	else if (ft_strchr("NSEW", map2d_char) != 0)
		put_pixel(img, j, i, convert_color(0xFFFFFF));
	else if (ft_strchr("PQ", map2d_char) != 0)
		put_pixel(img, j, i, convert_color(0xFF0000));
	else
		put_pixel(img, j, i, convert_color(0xA09C9C));
}

void	print_minimap(t_map *minimap, mlx_image_t *img, t_player *p)
{
	double	x;
	double	y;
	int		i;
	int		j;
	int		size;
	
	size = 10;
	i = 0;
	j = 0;
	x = p->pos_x - 5;
	y = p->pos_y - 5;
	size = MINIMAP_SIZE / 9;
	while (i < MINIMAP_SIZE)
	{
		while (j < MINIMAP_SIZE)
		{
			if (((int)round(x) >= 0 && (int)round(x) < minimap->w_map)
				&& ((int)round(y) >= 0 && (int)round(y) < minimap->h_map))
				put_px_minimap(minimap->map2d[(int)round(y)][(int)round(x)], img, j, i);
			else
				put_pixel(img, j, i, convert_color(0xA09C9C));
			x = x + (1 / (double)size);
			j++;
		}
		y += (1 / (double)size);
		x = p->pos_x - 5;
		j = 0;
		i++;
	}
}

void	display_minimap(t_params *p)
{
	mlx_image_t	*img;

	img = p->win->minimap_img;
	p->win->minimap_img = mlx_new_image(p->win->window, 500, 500);
	print_minimap(p->map, p->win->minimap_img, p->player);
	display_square(5, p->win->minimap_img, convert_color(0x000000));
	mlx_delete_image(p->win->window, img);
	if (!p->win->minimap_img || (mlx_image_to_window(p->win->window,
				p->win->minimap_img, 10, 10) < 0))
		print_err_free_exit(p, ER_DEFAULT);
	mlx_set_instance_depth(p->win->minimap_img->instances, 1);
}
