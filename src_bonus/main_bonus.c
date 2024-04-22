/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:20 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

mlx_image_t	*set_img(t_window_settings *set)
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

/* void	print_map(t_list *head)
{
	t_list	*next;

	ft_printf_fd(1, "PRINT MAP :\n");
	if (head != NULL)
	{
		next = head;
		while (next != NULL)
		{
			next = head->next;
			ft_printf_fd(1, "%s", head->content);
			head = next;
		}
	}
}

void	print_map_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf_fd(1, "%s\n", map[i]);
		i++;
	}
} */

void	ft_error(t_window_settings *set)
{
	free(set);
	exit(EXIT_FAILURE);
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
		exit_fct(game);
	game->win = win;
	map_file_parsing(game, argv[1]);
	set_map_w_and_h(game);
	get_coord_start(game, game->map->map2d);
	win->window = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!win->window)
		exit_fct(game);
	win->img = set_img(win);
	game->player = init_new_players(game->start_p.dir, game->start_p.x,
			game->start_p.y);
	return (game);
}

int	main(int argc, const char **argv)
{
	t_params			*game;

	check_args(argc, argv);
	game = init_game(argv);
	if (load_images(game) == FALSE)
		exit_fct(game);
	raycasting(game, game->win, game->player);
	display_hands(game);
	display_minimap(game);
	init_command(game);
	mlx_loop(game->win->window);
	mlx_resize_hook(game->win->window, &resize_mlx, game->win);
	mlx_close_hook(game->win->window, &close_fct, game->win);
	//mlx_terminate(game->win->window);
	free_game(game);
	return (0);
}
