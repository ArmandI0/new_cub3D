/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:17:03 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 13:02:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	cursor_fct(double xpos, double ypos, void *param)
{
	t_params		*p;
	
	p = param;
	(void) ypos;
	if (xpos > 540)
	{
		rotation(p, 0.5);
	}
	else if (xpos < 540)
		rotation(p, -0.5);
	mlx_set_mouse_pos(p->win->window, 540, 360);
}
