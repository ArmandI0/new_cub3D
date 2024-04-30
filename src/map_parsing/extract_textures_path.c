/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/30 12:31:37 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_bool	look_for_double_param(t_list *texture_path[4])
{
	int		i;
	t_list	*double_param;
	char	*str;

	i = 0;
	while (i < 4 && texture_path[i] != NULL)
	{
		if (i == PARAM_NO)
			str = ft_strdup("NO");
		else if (i == PARAM_SO)
			str = ft_strdup("SO");
		else if (i == PARAM_EA)
			str = ft_strdup("EA");
		else if (i == PARAM_WE)
			str = ft_strdup("WE");
		double_param = get_line_with_str(texture_path[i]->next, str);
		free(str);
		if (double_param != NULL)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static t_errors	r_err_if_null(t_list *texture_path[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (texture_path[i] == NULL)
			return (ER_INVALID_MAP_NO_PATH);
		i++;
	}
	return (NO_ERR);
}

static int	put_path_if_not_null(t_params *game, t_list *texture_path[4],
		char *set)
{
	int		i;
	char	*path;

	i = -1;
	while (++i < 4 && texture_path[i] != NULL)
	{
		path = NULL;
		path = ft_strtrim((texture_path[i])->content, set);
		if (path == NULL || path[0] == 0)
			return (ER_INVALID_MAP_NULL_PATH);
		if (ft_strncmp(path, "NO", 2) != 0 && ft_strncmp(path, "SO", 2) != 0
			&& ft_strncmp(path, "WE", 2) != 0 && ft_strncmp(path, "EA", 2) != 0)
		{
			free(path);
			return (ER_INVALID_MAP_FILE);
		}
		ft_memset(path, ' ', 2);
		game->path_texture[i] = ft_strtrim(path, set);
		del_el_list(texture_path[i], game);
		free (path);
		if (game->path_texture[i] == NULL || (game->path_texture[i])[0] == 0)
			return (ER_INVALID_MAP_NULL_PATH);
	}
	return (NO_ERR);
}

static t_bool	check_access_paths(char *path_texture[4])
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(path_texture[i], O_RDONLY);
		if (fd == -1)
			return (FALSE);
		else
			close(fd);
		i++;
	}
	return (TRUE);
}

t_errors	extract_path_textures(t_params *game, t_list *head)
{
	t_list	*texture_path[4];
	int		r_value;

	texture_path[PARAM_NO] = get_line_with_str(head, "NO");
	texture_path[PARAM_SO] = get_line_with_str(head, "SO");
	texture_path[PARAM_EA] = get_line_with_str(head, "EA");
	texture_path[PARAM_WE] = get_line_with_str(head, "WE");
	if (look_for_double_param(texture_path) == TRUE)
		return (ER_INVALID_MAP_DOUBLE);
	r_value = r_err_if_null(texture_path);
	if (r_value != NO_ERR)
		return (r_value);
	r_value = put_path_if_not_null(game, texture_path, " \n");
	if (r_value != NO_ERR)
		return (r_value);
	if (check_access_paths(game->path_texture) == FALSE)
		return (ER_FILE_TEXTURE_N_FOUND);
	return (NO_ERR);
}
