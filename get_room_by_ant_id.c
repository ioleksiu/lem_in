/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_by_ant_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:41:35 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:41:44 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms			*get_room_by_ant_id(t_rooms *rooms, int id)
{
	t_rooms		*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->ant_num == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (rooms);
}
