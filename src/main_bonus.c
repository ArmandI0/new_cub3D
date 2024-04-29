/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:50:56 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

mlx_image_t	*set_img(t_window_settings *set, t_params *game)
{
	mlx_image_t	*img;

	img = mlx_new_image(set->window, set->window->width, set->window->height);
	if (!img || (mlx_image_to_window(set->window, img, 0, 0) < 0))
		print_err_free_exit(game, ER_DEFAULT);
	else
	{
		mlx_set_instance_depth(img->instances, 0);
		return (img);
	}
	return (NULL);
}

static void	set_map_w_and_h(t_params *game)
{
	int	i;

	i = 0;
	game->map->w_map = ft_strlen(game->map->map2d[0]);
	while (game->map->map2d[i] != NULL)
	{
		i++;
	}
	game->map->h_map = i;
}

static void	get_coord_start(t_params *game, char **map2d)
{
	int	x;
	int	y;

	y = 0;
	while (map2d[y] != NULL)
	{
		x = 0;
		while (map2d[y][x] != 0)
		{
			if (ft_strchr("NSEW", map2d[y][x]) != 0)
			{
				game->start_p.x = (double)x + 0.5;
				game->start_p.y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
}

static t_params	*init_game(const char **argv)
{
	t_params			*game;
	t_window_settings	*win;

	game = ft_calloc(1, sizeof(t_params));
	if (game == NULL)
		exit(1);
	win = ft_calloc(1, sizeof(t_window_settings));
	if (win == NULL)
		print_err_free_exit(game, ER_DEFAULT);
	game->win = win;
	map_file_parsing(game, argv[1]);
	game->sprites.nb_sprites = count_nb_sprites(game->map->map2d);
	if (game->sprites.nb_sprites == 0)
		print_err_free_exit(game, ER_NB_SPRITES);
	set_map_w_and_h(game);
	get_coord_start(game, game->map->map2d);
	win->window = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!win->window)
		print_err_free_exit(game, ER_DEFAULT);
	win->img = set_img(win, game);
	game->player = init_new_players(game->start_p.dir, game->start_p.x,
			game->start_p.y);
	game->time_start = get_current_time();
	return (game);
}

int	main(int argc, const char **argv)
{
	t_params			*game;

	check_args(argc, argv);
	game = init_game(argv);
	if (load_images(game) == FALSE)
		print_err_free_exit(game, ER_LOAD_PNG);
	init_command(game);
	init_display_anims(game);
	mlx_loop(game->win->window);
	mlx_resize_hook(game->win->window, &resize_mlx, game->win);
	mlx_close_hook(game->win->window, &close_fct, game->win);
	free_game(game);
	return (0);
}
