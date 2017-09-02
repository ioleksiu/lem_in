/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   muravei_idi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:22:13 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:22:15 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			muravei_alloc(t_rooms *temp, t_lemin *lem)
{
	int			i;

	while (temp)
	{
		temp->ant_num = -1;
		temp = temp->next;
	}
	lem->is_ant_finished = (int*)malloc(sizeof(int) * lem->n_ants);
	i = -1;
	while (++i < lem->n_ants)
		lem->is_ant_finished[i] = 1;
}

void			muravei_idi1(t_lemin *lem, t_ways *ways, t_rooms *room,
				t_rooms *rooms)
{
	int			pos;
	t_rooms		*next_room;

	while (ways)
	{
		pos = ft_room_position(ways->way, lem->room_num, room->id);
		if (pos != -1)
		{
			next_room = find_room_by_id(rooms, ways->way[pos + 1]);
			if (next_room->ant_num == -1)
			{
				room->ant_num = -1;
				if (next_room->id == lem->room_num - 1)
				{
					lem->n_ants--;
					lem->is_ant_finished[lem->i] = 0;
				}
				else
					next_room->ant_num = lem->i + 1;
				print_results(lem->i + 1, next_room->r_name);
				break ;
			}
		}
		ways = ways->next;
	}
}

void			muravei_idi(t_lemin *lem, t_rooms *rooms)
{
	int			ant_num;
	t_rooms		*room;
	t_ways		*ways;
	t_rooms		*temp;

	temp = rooms;
	muravei_alloc(temp, lem);
	ant_num = lem->n_ants;
	while (lem->n_ants != 0)
	{
		lem->i = -1;
		while (++lem->i < ant_num)
			if (lem->is_ant_finished[lem->i] == 1)
			{
				ways = lem->ways;
				room = get_room_by_ant_id(rooms, lem->i + 1);
				muravei_idi1(lem, ways, room, rooms);
			}
		write(1, "\n", 1);
	}
}
