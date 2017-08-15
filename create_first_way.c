/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:48:17 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:48:23 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_fist_way(t_lemin *lem)
{
	int	i;

	i = -1;
	lem->ways = (t_ways*)malloc(sizeof(t_ways));
	lem->ways->way = (int*)malloc(sizeof(int) * lem->room_num);
	lem->ways->next = NULL;
	lem->ways->way_len = 0;
	while (++i < lem->room_num)
	{
		lem->ways->way[i] = lem->visited[i];
		if (lem->visited[i] != -1)
			lem->ways->way_len++;
	}
}
