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

void	muravei_idi(t_lemin *lem, t_rooms *rooms)
{
  int ant_num;
  int *is_ant_finished;
  int i;
  int pos;
  t_rooms*room;
  t_rooms *next_room;
  t_ways *ways;
  t_rooms *temp;

  temp = rooms;
  while (temp)
    {
      temp->ant_num = -1;
      temp = temp->next;
    }
  ant_num = lem->n_ants;
  is_ant_finished = (int*)malloc(sizeof(int) * lem->n_ants);
  i = -1;
  while (++i < lem->n_ants)
    is_ant_finished[i] = 1;
  while (lem->n_ants != 0)
    {
      i = -1;
      while (++i < ant_num)
	if (is_ant_finished[i] == 1)
	  {
	    ways = lem->ways;
	    room = get_room_by_ant_id(rooms, i + 1);
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
			    is_ant_finished[i] = 0;
			  }
			else
			  next_room->ant_num = i + 1;
			print_results(i+1, next_room->r_name);
			break ;
		      }
		  }
		ways = ways->next;
	      }
	  }
      write(1, "\n", 1);
    }
}
