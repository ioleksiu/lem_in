/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:39:22 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 18:39:48 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_link(char **link)
{
	int		i;

	i = 0;
	while (link[i])
	{
		free(link[i]);
		i++;
	}
	free(link);
}

t_lemin		*add_link(t_lemin *lem, t_rooms *rooms, char *str)
{
	char	**link;
	int		id[2];

	valid_link(str, rooms, lem);
	if (lem->matrix == NULL)
		create_matrix(lem);
	link = ft_strsplit(str, '-');
	id[0] = find_id(rooms, link[0]);
	id[1] = find_id(rooms, link[1]);
	lem->matrix[id[0]][id[1]] = 1;
	lem->matrix[id[1]][id[0]] = 1;
	//free(link);
	free_link(link);
	//free(str);
	return (lem);
}
