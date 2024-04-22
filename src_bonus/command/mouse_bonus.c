/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:17:03 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 13:29:25 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

#include <sys/time.h>

static size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	cursor_fct(double xpos, double ypos, void *param)
{
	t_params	*p;
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
		p = param;
		(void) ypos;
		if (xpos > WIDTH / 2)
			rotation(p, SENSIVITY);
		else if (xpos < WIDTH / 2)
			rotation(p, -SENSIVITY);
		mlx_set_mouse_pos(p->win->window, WIDTH / 2, HEIGHT / 2);
	}
}
