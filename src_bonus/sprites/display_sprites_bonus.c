/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 16:41:28 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static void	sort_sprites(int *sprites_dist, int *sprites_order, int nb_sprites)
{
	int	i;
	int	j;
	int tmp;
	int tmp2;

	i = 0;
	j = 0;
	while (i <= nb_sprites - 1)
	{
		while (j <= nb_sprites - 1)
		{
			if (sprites_dist[i] < sprites_dist[j])
			{
				tmp = sprites_order[i];
				tmp2 = sprites_dist[i];
				sprites_order[i] = sprites_order[j];
				sprites_dist[i] = sprites_dist[j];
				sprites_order[j] = tmp;
				sprites_dist[j] = tmp2;
			}
			j++;
		}
		j = i + 1;
		i++;
	}	
}

static int *get_sprite_order(t_sprites sprite, t_player *p)
{
	int	i;
	int *sprite_order;
	int *sprite_dist;

	sprite_order = ft_calloc(sprite.nb_sprites, sizeof(int));
	if (!sprite_order)
		return (NULL);
	sprite_dist = ft_calloc(sprite.nb_sprites, sizeof(int));
	if (!sprite_dist)
	{
		free (sprite_order);
		return (NULL);
	}
	i = 0;
	while (i < sprite.nb_sprites)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((p->pos_x - sprite.pos_x[i]) * (p->pos_x - sprite.pos_x[i]) + (p->pos_y - sprite.pos_y[i]) * (p->pos_y - sprite.pos_y[i]));
		i++;
	}
	sort_sprites(sprite_dist, sprite_order, sprite.nb_sprites);
	return (sprite_order);
}

static void	loop_put_pixel_sprite(t_coord_sprite_screen *s, double dist_bufr[WIDTH],
	t_window_settings *win, mlx_image_t *sprites_img)
{
	int	ver_line;
	int	y_px;
	int	tex_x;
	int	tex_y;
	int	color;

	ver_line = s->x_start;
	if (ver_line < 0)
		ver_line = 0;
	while (ver_line < s->x_end && ver_line < WIDTH)
	{
        tex_x = (int)((ver_line - s->x_start) * sprites_img->width / s->w);
       	if (s->matrix.y > 0 && s->matrix.y < dist_bufr[ver_line])
		{
			y_px = s->y_start - 1;
			while (++y_px < s->y_end)
			{
				tex_y = (int)((y_px - s->y_start) * sprites_img->height / s->h);
				color = get_color_px_img(tex_x, tex_y, sprites_img);
				if (color != -1)
					mlx_put_pixel(win->img, ver_line, y_px, color);
			}
		}
		ver_line++;
    }
}

t_bool draw_sprites(double dist_bufr[WIDTH], t_sprites sprites, t_player *p,
	t_window_settings *win)
{
	int 					i;
	int 					*order;
	t_coord_sprite_screen	*s;

	order = get_sprite_order(sprites, p);
	if (!order)
		return (FALSE);
	i = 0;
	
	while (i < sprites.nb_sprites)
	{
		if (sprites.pos_x[order[i]] >= 0 && sprites.pos_y[order[i]] >= 0)
		{
			s = ft_calloc(1, sizeof(t_coord_sprite_screen));
			if (!s)
				return (FALSE);
			s->matrix = get_pos_sprite_transformed(i, p, sprites, order);
			get_pos_vert_sprite(s, s->matrix);
			get_pos_horiz_sprite(s, s->matrix);
			loop_put_pixel_sprite(s, dist_bufr, win, sprites.img[0]);
			free (s);			
		}
		i++;
	}
	return (TRUE);
}
