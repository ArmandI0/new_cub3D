/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/09 14:35:18 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_bool	check_all_wall_around(char **map, int i, int j)
{
	if (map[i][j + 1] == 0)
		return (FALSE);
	if (i == 0 || j == 0)
		return (FALSE);
	if (map[i - 1][j] == ' ')
		return (FALSE);
	if (map [i + 1] != NULL && map[i + 1][j] == ' ')
		return (FALSE);
	if (map[i][j + 1] == ' ')
		return (FALSE);
	if (map[i][j - 1] == ' ')
		return (FALSE);
	return (TRUE);
}

static t_bool	check_if_missing_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (ft_strchr("0NSEW", map[i][j]) != 0)
			{
				if (check_all_wall_around(map, i, j) == FALSE)
					return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_bool		check_walls(t_params *game)
{
	char	**map;
	int		nb_lines;
	int		i;

	i = 0;
	map = game->map->map2d;
	nb_lines = game->nb_map_lines;
	while (map[0][i] != 0)
	{
		if (ft_strchr("1 ", map[0][i]) == 0)
			return (ER_MISSING_WALLS);
		if (ft_strchr("1 ", map[nb_lines - 1][i]) == 0)
			return (ER_MISSING_WALLS);
		i++;
	}
	if (check_if_missing_wall(map) == TRUE)
		return (ER_MISSING_WALLS);
	return (0);
}
