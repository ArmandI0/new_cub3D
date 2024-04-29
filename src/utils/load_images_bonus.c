/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/29 19:50:56 by nledent          ###   ########.fr       */
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
	if (load_anim(game) == FALSE)
		return (FALSE);
	if (load_sprites(game) == FALSE)
		return (FALSE);
	if (load_texts(game) == FALSE)
		return (FALSE);
	return (TRUE);
}
