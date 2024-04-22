/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:40:47 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 17:24:08 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/src/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# define WIDTH 1024
# define HEIGHT 720
# define EAST_WEST 0
# define NORTH_SOUTH 1

typedef int	t_bool;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_window_settings
{
	int			w;
	int			h;
	mlx_image_t	*img;
	mlx_image_t	*player_img;
	mlx_image_t	*minimap_img;
	mlx_t		*window;
}				t_window_settings;

typedef	struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef	struct s_coord_sprite_screen
{
	double	h;
	double	w;
	double	x_middle;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
	t_coord	matrix;
}				t_coord_sprite_screen;

typedef struct s_map
{
	char	**map2d;
	int		w_map;
	int		h_map;
}				t_map;

typedef struct s_var_raycasting
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		pos_x;
	int		pos_y;
	int		step_x;
	int		step_y;
	double	dt_x;
	double	dt_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_dist;
	int		start;
	int		end;
}			t_var_raycasting;


typedef enum cb_errors
{
	ER_NB_ARGS,
	ER_MAP_TYPE,
	ER_FILE_N_FOUND,
	ER_EXTRACTION_MAP,
	ER_INVALID_MAP_DOUBLE,
	ER_INVALID_MAP_FILE,
	ER_INVALID_MAP_NULL_PATH,
	ER_INVALID_MAP_NULL_COLOR,
	ER_FILE_TEXTURE_N_FOUND,
	ER_INVALID_MAP_CHARACTER,
	ER_INVALID_MAP_EMPTY_LINES,
	ER_NO_STARTPOINT,
	ER_TOO_MANY_STARTPOINT,
	ER_MISSING_WALLS,
}			t_errors;

typedef enum cb_param_type
{
	PARAM_NO,
	PARAM_SO,
	PARAM_EA,
	PARAM_WE,
	PARAM_F,
	PARAM_C,
}			t_param_type;

typedef struct s_startpoint
{
	double				x;
	double				y;
	t_param_type	dir;
}		t_startpoint;

typedef struct s_sprites
{
	mlx_image_t	*img[2];
	int			nb_sprites;
	int			nb_remaining;
	int			*pos_x;
	int			*pos_y;
}		t_sprites;

typedef struct s_display
{
	u_int64_t	*spagh_eaten;
	u_int64_t	one_min;
	t_bool		dead;
	u_int64_t	start_game;
	u_int64_t	time_given;
}		t_display;

typedef struct s_params
{
	t_map		*map;
	t_window_settings *win;
	t_player		*player;
	int			nb_map_lines;
	char		*path_texture[4];
	mlx_texture_t	*texture[4];
	mlx_image_t	*anim_p[5];
	t_sprites	sprites;
	int			anim_p_pattern[9];
	int			ceiling_color;
	int			floor_color;
	t_list		*head_list_lines;
	t_startpoint	start_p;
	t_display	times;
}			t_params;

/* PARSING FUNCTIONS */
void		map_file_parsing(t_params *game, const char *filepath);
t_bool		extract_file_into_list(t_params *game, const char *filepath);
t_errors	extract_path_textures(t_params *game, t_list *head);
t_errors	extract_colors(t_params *game, t_list *head);
t_list		*get_line_with_str(t_list *head, char *str);
t_errors	extract_rgb_str(t_params *game, t_list *color,
			char *set, t_param_type p_type);
t_errors	extract_map(t_params *game);
t_bool		is_line_empty(t_list *last);
t_bool		map_to_tab(t_params *game, t_list *head);
t_bool		check_walls(t_params *game);
t_bool		load_images(t_params *game);

/* SPRITES FUNCTIONS */
t_bool		load_sprites(t_params *game);
t_bool		draw_sprites(double dist_buffer[WIDTH], t_sprites sprites, t_player *p, t_window_settings *win);
void		get_pos_vert_sprite(t_coord_sprite_screen *s, t_coord sprite_matrix);
void		get_pos_horiz_sprite(t_coord_sprite_screen *s, t_coord sprite_matrix);
t_coord	get_pos_sprite_transformed(int i, t_player *p, t_sprites sprites, int *sprite_order);
void		remove_sprite_collision(t_player *p, t_sprites sprites, t_params *game);

/* EXEC FUNCTIONS */
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		resize_mlx(int32_t width, int32_t height, void *param);
void		put_pixel(mlx_image_t *img, uint32_t x,
						uint32_t y, int color);
void		close_fct(void *param);
t_map *		init_argument(void); // init the data structure
void 		display_minimap(t_params *p);
void		ft_error(t_window_settings *set);
void		display_square(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color, t_bool border);
void		print_player(t_params *p);
t_player	*init_new_players(t_param_type direction, double x, double y);
void		del_txt_tmp(mlx_texture_t **tmp, int nb);
void		draw_ver_line(t_params *game, t_var_raycasting *var, int x_position,  int side);

/* FREE FUNCTIONS */
void	free_game(t_params *game);
void	free_path_textures(t_params *game);
void	free_el_list(t_list *element);
void	free_textures(t_params *game);
void	free_img_anim(t_params *game);
void	free_img_sprites(t_params *game);

/* RAY CASTING FUNCTIONS*/
t_bool  raycasting(t_params *game, t_window_settings *set, t_player *p);
void	rotation(t_params *p, double step);
void	translate_player_l_to_r(t_player *player, double step,  char** map);
void 	translate_player_forward(t_player *player, double step, char** map);
void 	rotate_player(t_player *player, double angle);

/* UTILS FUNCTIONS */
void	check_args(int argc, const char **argv);
void	print_error(t_errors error);
void	del_el_list(t_list *element, t_params *game);
mlx_image_t	*set_img(t_window_settings *set);
void	cursor_fct(double xpos, double ypos, void *param);
void	init_command(t_params *game);
void	exit_fct(t_params *param);
void	rotation(t_params *p, double step);
mlx_image_t	*set_img(t_window_settings *set);
int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue);
int		get_color_px_txt(uint32_t x, uint32_t y, mlx_texture_t *txt);
uint32_t	convert_color(unsigned int color);
int		get_color_px_img(uint32_t x, uint32_t y, mlx_image_t *img);
u_int64_t	time_to_ms(void);
void	init_times_displays(t_params *game);

/* DISPLAY FUNCTIONS */
void	display_infos(t_params *game);
void	display_all(t_params *game);
void	display_hands(t_params *game);
void	display_sprites(t_params *game);
void	display_welcome(mlx_t *mlx, t_params *game);
void	display_success(mlx_t *mlx, t_params *game);

#endif