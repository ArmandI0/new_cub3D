/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/05/22 10:33:44 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static t_bool	atoi_rgb(int rgb[3], char **split_rgb)
{
	rgb[0] = ft_atoi(split_rgb[0]);
	if (rgb[0] < 0 || rgb[0] > 255)
		return (FALSE);
	rgb[1] = ft_atoi(split_rgb[1]);
	if (rgb[1] < 0 || rgb[1] > 255)
		return (FALSE);
	rgb[2] = ft_atoi(split_rgb[2]);
	if (rgb[2] < 0 || rgb[2] > 255)
		return (FALSE);
	return (TRUE);
}

static int	put_split_rgb_to_int(int rgb[3], char **split_rgb)
{
	char	*red;
	char	*green;
	char	*blue;
	int		color;

	color = -2;
	red = ft_itoa(rgb[0]);
	green = ft_itoa(rgb[1]);
	blue = ft_itoa(rgb[2]);
	if (ft_strcmp(split_rgb[0], red) == 0
		&& ft_strcmp(split_rgb[1], green) == 0
		&& ft_strcmp(split_rgb[2], blue) == 0)
		color = rgb_to_int(rgb[0], rgb[1], rgb[2]);
	free (red);
	free (green);
	free (blue);
	return (color);
}

static int	str_rgb_to_int(char *rgb_str, char *set)
{
	int		color;
	int		rgb[3];
	char	**split_rgb;
	char	*rgb_trim;
	int		i;

	i = 0;
	rgb_trim = ft_strtrim(rgb_str, set);
	if (rgb_trim == NULL || rgb_trim[0] == 0)
	{
		free(rgb_trim);
		return (-2);
	}
	split_rgb = ft_split(rgb_trim, ',');
	while (split_rgb[i] != NULL)
		i++;
	if (i == 3 && atoi_rgb(rgb, split_rgb) == TRUE)
		color = put_split_rgb_to_int(rgb, split_rgb);
	else
		color = -2;
	free_split(split_rgb);
	free(rgb_trim);
	if (color == -2)
		return (-2);
	return (convert_color(color));
}

t_errors	extract_rgb_str_c(t_params *game, t_list *color, char *set)
{
	char	*rgb;

	rgb = NULL;
	if (color != NULL)
	{
		rgb = ft_strtrim(color->content, set);
		if (rgb == NULL || rgb[0] == 0 || rgb[0] != 'C')
		{
			free(rgb);
			return (ER_COLOR);
		}
		rgb[0] = ' ';
		game->ceiling_color = str_rgb_to_int(rgb, set);
		put_line_to_nl(color, game);
		free (rgb);
		if (game->ceiling_color == -2)
			return (ER_COLOR);
	}
	return (0);
}

t_errors	extract_rgb_str_f(t_params *game, t_list *color, char *set)
{
	char	*rgb;

	rgb = NULL;
	if (color != NULL)
	{
		rgb = ft_strtrim(color->content, set);
		if (rgb == NULL || rgb[0] != 'F')
		{
			free(rgb);
			return (ER_COLOR);
		}
		rgb[0] = ' ';
		game->floor_color = str_rgb_to_int(rgb, set);
		put_line_to_nl(color, game);
		free (rgb);
		if (game->floor_color == -2)
			return (ER_COLOR);
	}
	return (0);
}
