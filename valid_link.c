/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:21:31 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:21:33 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_link(char *str, t_rooms *a, t_lemin *lem)
{
	char	**link;

	if (lem->is_link == 0)
		swap_start_end(a, lem);
	lem->is_link = 1;
	link = ft_strsplit(str, '-');
	if (count_char(str, '-') == 1)
		if (is_alnum_str(link[0]) && is_alnum_str(link[1]))
			if (find_room(link[0], a) && find_room(link[1], a)
			&& lem->is_start != 0 && lem->is_end != 0)
			{
				free_split(link);
				return (1);
			}
	ft_error();
	return (0);
}
