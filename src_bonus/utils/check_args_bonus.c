/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/13 20:35:57 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static t_bool	check_nb_args(int argc)
{
	if (argc != 2)
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	is_filepath_valid(const char *filepath)
{
	int	len_filepath;

	if (filepath == NULL)
		return (FALSE);
	len_filepath = ft_strlen(filepath);
	if (len_filepath < 5)
		return (FALSE);
	else if (ft_strcmp(&filepath[len_filepath - 4], ".cub") != 0)
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	is_map_accessible(const char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close (fd);
	return (TRUE);
}

void	check_args(int argc, const char **argv)
{
	if (check_nb_args(argc) == FALSE)
	{
		print_error(ER_NB_ARGS);
		exit (1);
	}
	else if (is_filepath_valid(argv[1]) == FALSE)
	{
		print_error(ER_MAP_TYPE);
		exit (1);
	}
	else if (is_map_accessible(argv[1]) == FALSE)
	{
		print_error(ER_FILE_N_FOUND);
		exit (1);
	}
}
