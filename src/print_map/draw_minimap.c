/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 14:36:16 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	display_border(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= size)
	{
		while (y <= size)
		{
			if ((y == 0 || y == size) || (x == 0 || x == size))
				put_pixel(img, start_x + x, start_y + y, color);
			y++;
		}
		y = 0;
		x++;
	}
	
}

void	display_square(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color, t_bool border)
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
	if (border == TRUE)
		display_border(start_x, start_y, size, img, convert_color(0x000000));
}

void print_minimap(t_map *minimap, mlx_image_t *img, t_player *p)
{
	double x;
	double y;
	int	i;
	int	j;
	int size = 10;
	int	a = 9;
	
	i = 0;
	j = 0;
	x = p->pos_x - 5;
	y = p->pos_y - 5;
	size = 15;
	while (i < a * size)
	{
		while (j < a * size)
		{
			if (((int)round(x) >= 0 && (int)round(x) < minimap->w_map) && ((int)round(y) >= 0 && (int)round(y) < minimap->h_map))
			{
				if (minimap->map2d[(int)round(y)][(int)round(x)] == '1')
					put_pixel(img, j, i, convert_color(0xA09C9C)); //display_square(j * size, i * size, size, set->minimap_img, convert_color(0x00D7FF), TRUE );
				else if (minimap->map2d[(int)round(y)][(int)round(x)] == '0')
					put_pixel(img, j, i, convert_color(0xFFFFFF));//display_square(j * size, i * size, size, set->minimap_img,convert_color(0xFFCF00), TRUE );
				else if (ft_strchr("NSEW", minimap->map2d[(int)round(y)][(int)round(x)]) != 0)
					put_pixel(img, j, i, convert_color(0xFFFFFF));//display_square(j * size, i * size, size, set->minimap_img, convert_color(0x00D7FF), TRUE);
				else
					put_pixel(img, j, i, convert_color(0xA09C9C));//display_square(j * size, i * size, size, set->minimap_img, convert_color(0x000000), FALSE);
			}		
			else
				put_pixel(img, j, i, convert_color(0xA09C9C));
			x= x + (1 / (double)size);
			j++;
		}
		y+= (1 / (double)size);
		x = p->pos_x - 5;
		j = 0;
		i++;
	}
	display_square((135 / 2) - 2, (135 / 2) - 2, 5, img, convert_color(0x000000), FALSE);

}

void display_minimap(t_params *p)
{
	mlx_image_t	*img;

	img = mlx_new_image(p->win->window, 500, 500);
	print_minimap(p->map, img, p->player);
	if (!img || (mlx_image_to_window(p->win->window, img, 10, 10) < 0))
		exit_fct(p);
	mlx_delete_image(p->win->window, p->win->minimap_img);
	p->win->minimap_img = img;
}
