/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:21:12 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:21:15 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swap_start_end(t_rooms *rooms, t_lemin *lem)
{
	t_rooms	*temp;

	if (lem->is_start == 0 || lem->is_end == 0)
		ft_error();
	temp = rooms;
	if (lem->is_end == 0)
		ft_error();
	swap_rooms(rooms, find_room_by_id(rooms, lem->start_id));
	while (temp->next)
		temp = temp->next;
	swap_rooms(temp, find_room_by_id(rooms, lem->end_id));
	lem->start_id = 0;
	lem->end_id = lem->room_num - 1;
}
