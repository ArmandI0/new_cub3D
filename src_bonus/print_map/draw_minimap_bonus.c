/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/30 12:29:12 by aranger          ###   ########.fr       */
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

static t_bool	ch_bo(double x, double y, t_params *game)
{
	t_map	*minimap;

	minimap = game->map;
	if (((int)round(x) >= 0 && (int)round(x) < minimap->w_map)
		&& ((int)round(y) >= 0 && (int)round(y) < minimap->h_map))
		return (TRUE);
	return (FALSE);
}

static void	put_px_minimap(double y, t_params *p, int i, char **map2d)
{
	int		j;
	double	x;
	int		size;

	j = 0;
	x = p->player->pos_x - 5;
	size = MINIMAP_SIZE / 9;
	while (j < MINIMAP_SIZE)
	{
		if (ch_bo(x, y, p) && map2d[(int)round(y)][(int)round(x)] == '1')
			put_pixel(p->win->minimap_img, j, i, convert_color(0xA09C9C));
		else if (ch_bo(x, y, p) && map2d[(int)round(y)][(int)round(x)] == '0')
			put_pixel(p->win->minimap_img, j, i, convert_color(0xFFFFFF));
		else if (ch_bo(x, y, p)
			&& ft_strchr("NSEW", map2d[(int)round(y)][(int)round(x)]) != 0)
			put_pixel(p->win->minimap_img, j, i, convert_color(0xFFFFFF));
		else if (ch_bo(x, y, p)
			&& ft_strchr("PQ", map2d[(int)round(y)][(int)round(x)]) != 0)
			put_pixel(p->win->minimap_img, j, i, convert_color(0xFF0000));
		else
			put_pixel(p->win->minimap_img, j, i, convert_color(0xA09C9C));
		j++;
		x = x + (1 / (double)size);
	}
}

void	print_minimap(t_params *game, t_player *p)
{
	double	y;
	int		i;
	int		size;

	i = 0;
	y = p->pos_y - 5;
	size = MINIMAP_SIZE / 9;
	while (i < MINIMAP_SIZE)
	{
		put_px_minimap(y, game, i, game->map->map2d);
		y += (1 / (double)size);
		i++;
	}
}

void	display_minimap(t_params *p)
{
	mlx_image_t	*img;

	img = p->win->minimap_img;
	p->win->minimap_img = mlx_new_image(p->win->window, 500, 500);
	print_minimap(p, p->player);
	display_square(5, p->win->minimap_img, convert_color(0x000000));
	mlx_delete_image(p->win->window, img);
	if (!p->win->minimap_img || (mlx_image_to_window(p->win->window,
				p->win->minimap_img, 10, 10) < 0))
		print_err_free_exit(p, ER_DEFAULT);
	mlx_set_instance_depth(p->win->minimap_img->instances, 1);
}
