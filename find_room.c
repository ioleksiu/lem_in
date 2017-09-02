/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:17:28 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:17:34 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_room(char *room, t_rooms *a)
{
	t_rooms	*temp;

	temp = a;
	if (temp == NULL)
		return (0);
	if (ft_strequ(temp->r_name, room))
		return (1);
	while (temp->next)
	{
		temp = temp->next;
		if (ft_strequ(temp->r_name, room))
			return (1);
	}
	return (0);
}
