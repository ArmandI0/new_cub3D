/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/09 14:23:46 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static t_bool	check_identifier_name_only(char *identifier_in_str, int len_identifier)
{
	if (identifier_in_str[len_identifier] == 0)
		return (TRUE);
	else if (identifier_in_str[len_identifier] == ' ')
		return (TRUE);
	else
		return (FALSE);
}

t_list	*get_line_with_str(t_list *head, char *identifier)
{
	t_list	*line;
	int		len_str;
	int		len_id;
	char	*identifier_in_str;

	len_id = ft_strlen(identifier);
	if (head != NULL)
	{
		line = head;
		while (line != NULL)
		{
			if (line->content)
				len_str = ft_strlen(line->content);
			else
				len_str = 0;
			identifier_in_str = ft_strnstr(line->content, identifier, len_str);
			if (identifier_in_str != NULL && check_identifier_name_only(identifier_in_str, len_id) == TRUE)
				return (line);
			line = line->next;
		}
	}
	return (NULL);
}

u_int64_t	time_to_ms(void)
{
	u_int64_t		time_ms;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time_ms = (now.tv_sec * 1000);
	time_ms += (now.tv_usec / 1000);
	return (time_ms);
}
