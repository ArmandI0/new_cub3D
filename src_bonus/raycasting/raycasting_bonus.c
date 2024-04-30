/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:49:25 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 20:09:29 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static double	find_next_side(double ray)
{
	double	delta;

	if (ray == 0)
		delta = 1e30;
	else
		delta = fabs(1 / ray);
	return (delta);
}

static void	incr_side_dist(t_var_raycasting *v, t_player *p)
{
	if (v->ray_dir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (p->pos_x - v->pos_x) * v->dt_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->pos_x + 1 - p->pos_x) * v->dt_x;
	}
	if (v->ray_dir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (p->pos_y - v->pos_y) * v->dt_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->pos_y + 1 - p->pos_y) * v->dt_y;
	}
}

static void	set_var(t_var_raycasting *v, t_player *p, int i)
{
	v->ray_dir_x = p->dir_x + p->plane_x * (2 * i / (double)(WIDTH) - 1);
	v->ray_dir_y = p->dir_y + p->plane_y * (2 * i / (double)(WIDTH) - 1);
	v->dt_x = find_next_side(v->ray_dir_x);
	v->dt_y = find_next_side(v->ray_dir_y);
	v->pos_x = (int)p->pos_x;
	v->pos_y = (int)p->pos_y;
	incr_side_dist(v, p);
}

static void	set_start_and_end(t_var_raycasting *var)
{
	int	h_line;

	h_line = (int)(HEIGHT / var->perp_dist);
	var->start = -h_line / 2 + HEIGHT / 2 ;
	var->end = h_line / 2 + HEIGHT / 2;
}

t_bool	raycasting(t_params *game, t_window_settings *set, t_player *p)
{
	int					i;
	t_var_raycasting	var;
	double				dist_buffer[WIDTH];
	mlx_image_t			*img;

	i = 0;
	img = set->img;
	set->img = mlx_new_image(set->window, WIDTH, HEIGHT);
	if (!set->img)
		return (FALSE);
	while (i < WIDTH)
	{
		set_var(&var, p, i);
		get_side_put_perp_dist(&var, game);
		set_start_and_end(&var);
		dist_buffer[i] = var.perp_dist;
		draw_ver_line(game, &var, i, var.side);
		i++;
	}
	draw_sprites(dist_buffer, game->sprites, game->player, game->win);
	mlx_delete_image(set->window, img);
	mlx_image_to_window(set->window, set->img, 0, 0);
	mlx_set_instance_depth(set->img->instances, 0);
	return (TRUE);
}
