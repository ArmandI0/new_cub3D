/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors_data_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/19 16:19:04 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"


static t_bool	look_for_double_param(t_list *color_str, t_param_type p_type)
{
	t_list	*double_param;
	char	*str;

	str = NULL;
	if (color_str != NULL)
	{
		if (p_type == PARAM_F)
			str = ft_strdup("F");
		else if (p_type == PARAM_C)
			str = ft_strdup("C");
		double_param = get_line_with_str(color_str->next, str);
		free(str);
		if (double_param != NULL)
			return (TRUE);
	}
	return (FALSE);
}

/*
Record the path of default textures in the game parameters if there is no path found in the .cub.
Record first "texture_x" and then replace 'x' by the good number.
*/
static void	put_color_default_if_null(t_params *game, t_list *color_str,
		t_param_type color)
{
	if (color_str == NULL)
	{
		if (color == PARAM_F)
			game->floor_color = convert_color(rgb_to_int(200, 150, 100));
		else if (color == PARAM_C)
			game->ceiling_color = convert_color(rgb_to_int(150, 200, 255));
	}
}

t_errors	extract_colors(t_params *game, t_list *head)
{
	t_list	*floor;
	t_list	*ceiling;
	int		r_value;

	floor = get_line_with_str(head, "F");
	ceiling = get_line_with_str(head, "C");
	if (look_for_double_param(floor, PARAM_F) == TRUE
		|| look_for_double_param(ceiling, PARAM_C) == TRUE)
		return (ER_INVALID_MAP_DOUBLE);
 	put_color_default_if_null(game, floor, PARAM_F);
 	put_color_default_if_null(game, ceiling, PARAM_C);
	ft_printf_fd(1, "ceiling color game : %d\n", game->ceiling_color);
	r_value = extract_rgb_str(game, floor, " \n", PARAM_F);
	ft_printf_fd(1, "floor color game : %d\n", game->floor_color);
	if (r_value != 0)
		return (r_value);
	r_value = extract_rgb_str(game, ceiling, " \n", PARAM_C);
	if (r_value != 0)
		return (r_value);
	return (0);
}
