/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:50:25 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:50:27 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_room(char *str, t_rooms *rooms, t_lemin *lem)
{
	if (ft_strchr(str, ' '))
	{
		valid_room(str, rooms, lem);
		return (1);
	}
	return (0);
}
