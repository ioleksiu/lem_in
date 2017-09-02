/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <ioleksiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:04:18 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/18 14:02:08 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_split(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void			free_rooms(t_rooms *rooms)
{
	t_rooms		*tmp;

	while (rooms)
	{
		tmp = rooms;
		rooms = rooms->next;
		free(tmp->r_name);
		free(tmp);
	}
}

void			free_ways(t_ways *ways)
{
	t_ways		*tmp;

	while (ways)
	{
		tmp = ways;
		ways = ways->next;
		free(tmp->way);
		free(tmp);
	}
}

void			free_lem_struct(t_lemin *lem)
{
	int			i;

	i = 0;
	while (i < lem->room_num)
	{
		free(lem->matrix[i]);
		i++;
	}
	free(lem->matrix);
	free(lem->is_visited);
	free(lem->queue);
	free(lem->visited);
	free(lem->input);
	free(lem->is_ant_finished);
	free(lem);
}

void			free_all(t_lemin *lem, t_rooms *rooms)
{
	free_rooms(rooms);
	free_ways(lem->ways);
	free_lem_struct(lem);
}
