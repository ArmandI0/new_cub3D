
#include "../../includes/cub3D_bonus.h"

void	rotation(t_params *p, double step)
{
	rotate_player(p->player, step);
}

static void translation(t_params *p, double step, t_bool tr)
{
	if (tr == FALSE)
		translate_player_forward(p->player, step, p->map->map2d);
	else
		translate_player_l_to_r(p->player, step, p->map->map2d);
	remove_sprite_collision(p->player, p->sprites, p);	
	display_hands(p);
}

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		translation(p, SPEED, FALSE);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		translation(p, -SPEED, FALSE);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		translation(p, SPEED, TRUE);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		translation(p, -SPEED, TRUE);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotation(p, SENSIVITY);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotation(p, -SENSIVITY);
}

void	refresh_window(t_params *p)
{
	static size_t	start_time = 0;
	size_t			time;

	time = get_current_time();
	if (start_time == 0)
		start_time = get_current_time();
	if (time - start_time < 33)
		return ;
	else
	{
		start_time = get_current_time();
		display_all(p);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_P)
		printf("pos x : %f\npos y : %f\n", p->player->pos_x, p->player->pos_y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(p->win->window);
	}
	translation_key(keydata, param);
}
