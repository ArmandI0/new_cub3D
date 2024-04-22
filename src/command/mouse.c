/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:17:03 by aranger           #+#    #+#             */
/*   Updated: 2024/04/20 12:13:35 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <sys/time.h>

size_t	get_current_time(void)
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
	{
		printf("time %ld\n",time);
		return ;
	}
	else
	{
		ft_printf_fd(2, "PAS DE RETURN C'EST MORT time = %d\n", time);
		start_time = get_current_time();
		p = param;
		(void) ypos;
		if (xpos > 540)
			rotation(p, -2);
		else if (xpos < 540)
			rotation(p, 2);
		mlx_set_mouse_pos(p->win->window, 540, 360);
	}	

}
