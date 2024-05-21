/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/05/21 21:55:15 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

static t_bool	check_identifier_name_only(char *identifier_in_str,
	int len_identifier, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (&str[i] != identifier_in_str)
		return (FALSE);
	else if (identifier_in_str[len_identifier] == 0)
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
	char	*id_in_str;
	char	*str;

	len_id = ft_strlen(identifier);
	if (head != NULL)
	{
		line = head;
		while (line != NULL)
		{
			str = line->content;
			if (line->content)
				len_str = ft_strlen(line->content);
			else
				len_str = 0;
			id_in_str = ft_strnstr(line->content, identifier, len_str);
			if (id_in_str != NULL
				&& check_identifier_name_only(id_in_str, len_id, str) == TRUE)
				return (line);
			line = line->next;
		}
	}
	return (NULL);
}
