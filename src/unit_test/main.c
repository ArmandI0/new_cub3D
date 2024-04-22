/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/15 20:52:32 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

mlx_image_t *set_img(t_window_settings *set)
{
	mlx_image_t *img;

	img = mlx_new_image(set->window, set->window->width, set->window->height);
	if (!img || (mlx_image_to_window(set->window, img, 0, 0) < 0))
		ft_error(set);
	else
	{
		mlx_set_instance_depth(img->instances, 0);
		return (img);
	}
	return (NULL);
}

void ft_error(t_window_settings *set)
{
	free(set);
	exit(EXIT_FAILURE);
}

static t_params *init_game(const char **argv)
{
	t_params *game;
	t_window_settings *win;

	(void)argv;
	game = ft_calloc(1, sizeof(t_params));
	if (game == NULL)
		exit(1);
	win = ft_calloc(1, sizeof(t_window_settings));
	if (win == NULL)
		exit_fct(game);
	game->win = win;
	win->window = mlx_init(WIDTH, HEIGHT, "UNIT_TEST", true);
	if (!win->window)
		exit_fct(game);
	win->img = set_img(win);
	return (game);
}

static int texture_to_img(mlx_texture_t* texture, mlx_image_t *img)
{
	int color = 0;
	uint32_t x = 0;
	uint32_t y = 0;
	uint32_t pixel_index;
	uint32_t width = texture->width;

	while (y < texture->height)
	{
		x = 0;
		while (x < width)
		{
			pixel_index = y * texture->width * texture->bytes_per_pixel + x * texture->bytes_per_pixel;
			color = convert_color(rgb_to_int(texture->pixels[pixel_index], texture->pixels[pixel_index + 1], texture->pixels[pixel_index + 2]));
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int main(int argc, const char **argv)
{
	t_params *game;
	mlx_texture_t *texture;
	
	texture = mlx_load_png("../../textures/leaves_128x128.png");
	(void)argc;
	(void)argv;
	
	game = init_game(argv);
	//img_texture = mlx_texture_to_image(game->win->window, texture);
	texture_to_img(texture, game->win->img);
	mlx_image_to_window(game->win->window, game->win->img, 0, 0);
	mlx_put_pixel(game->win->img, WIDTH / 2, HEIGHT / 2, convert_color(rgb_to_int(250, 200, 0)));
	mlx_loop(game->win->window);
	free_game(game);
	free(texture);
	return (0);
}
