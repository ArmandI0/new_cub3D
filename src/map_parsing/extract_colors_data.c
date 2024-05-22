/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/05/22 10:31:58 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

static void	exit_if_path_null(t_params *game, t_list *color_str)
{
	if (color_str == NULL)
	{
		print_err_free_exit(game, ER_COLOR);
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
	exit_if_path_null(game, floor);
	exit_if_path_null(game, ceiling);
	r_value = extract_rgb_str_f(game, floor, " \n");
	if (r_value != 0)
		return (r_value);
	r_value = extract_rgb_str_c(game, ceiling, " \n");
	if (r_value != 0)
		return (r_value);
	if (game->floor_color == game->ceiling_color)
		print_err_free_exit(game, ER_COLOR);
	return (0);
}
