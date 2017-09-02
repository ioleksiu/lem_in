/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_redundant_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:27:36 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:27:42 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_remove_redundant_path(t_lemin *lem)
{
	t_ways		*start;
	t_ways		*next;
	int			i;

	start = lem->ways;
	while (start)
	{
		i = 1;
		while (i < lem->room_num && start->way[i] != -1)
		{
			if (start->way[i] == lem->room_num - 1)
				break ;
			next = start->next;
			if (next == NULL)
				break ;
			while (next)
			{
				if (ft_room_in_path(lem->room_num, next->way, start->way[i]))
					ft_delete_path(&(lem->ways), &(next));
				next = next->next;
			}
			i++;
		}
		start = start->next;
	}
}
