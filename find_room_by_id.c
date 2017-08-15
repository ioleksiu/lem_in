/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room_by_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:20:33 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:20:36 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*find_room_by_id(t_rooms *rooms, int id)
{
	t_rooms	*temp;

	temp = rooms;
	while (temp && temp->id != id)
		temp = temp->next;
	if (temp->id == id)
		return (temp);
	ft_error();
	return (0);
}
