/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:16:32 by nledent           #+#    #+#             */
/*   Updated: 2024/04/09 14:23:40 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	print_error2(t_errors error)
{
	if (error == ER_INVALID_MAP_EMPTY_LINES)
		ft_printf_fd(2, "Invalid map : Empty lines in the map");
	else if (error == ER_NO_STARTPOINT)
		ft_printf_fd(2, "Invalid map : No startpoint");
	else if (error == ER_TOO_MANY_STARTPOINT)
		ft_printf_fd(2, "Invalid map : Too many startpoints");
	else if (error == ER_MISSING_WALLS)
		ft_printf_fd(2, "Invalid map : There are missing walls");
}

void	print_error(t_errors error)
{
	ft_printf_fd(2, "Error\n");
	if (error == ER_NB_ARGS)
		ft_printf_fd(2, "The game just need one argument : a *.cub map file");
	else if (error == ER_MAP_TYPE)
		ft_printf_fd(2, "The map file is not *.cub");
	else if (error == ER_FILE_N_FOUND)
		ft_printf_fd(2, "Invalid arg : file not found / bad access");
	else if (error == ER_INVALID_MAP_DOUBLE)
		ft_printf_fd(2, "Invalid map file : same identifier several times");
	else if (error == ER_INVALID_MAP_NULL_PATH)
		ft_printf_fd(2, "Invalid path : no path for at least one identifier");
	else if (error == ER_EXTRACTION_MAP)
		ft_printf_fd(2, "Problem with map extraction");
	else if (error == ER_FILE_TEXTURE_N_FOUND)
		ft_printf_fd(2, "Invalid texture path : file not found / bad access");
	else if (error == ER_INVALID_MAP_FILE)
		ft_printf_fd(2, "Invalid map file : bad syntax");
	else if (error == ER_INVALID_MAP_NULL_COLOR)
		ft_printf_fd(2, "Invalid map file : RGB color missing");
	else if (error == ER_INVALID_MAP_CHARACTER)
		ft_printf_fd(2, "Invalid map : Bad character");
	else
		print_error2(error);
	ft_printf_fd(2, "\n");
}
