/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 20:17:24 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	del_txt_tmp(mlx_texture_t **tmp, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (tmp[i])
			mlx_delete_texture(tmp[i]);
		i++;
	}
}

t_bool	load_images(t_params *game)
{
	if (load_textures(game) == FALSE)
		return (FALSE);
	return (TRUE);
}
