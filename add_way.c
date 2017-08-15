/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:30:07 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:30:11 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_way(t_lemin *lem)
{
	t_ways	*tmp;
	int		i;

	tmp = lem->ways;
	if (tmp == NULL)
		create_fist_way(lem);
	else
	{
		tmp = lem->ways;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_ways *)malloc(sizeof(t_ways));
		tmp->next->way = (int *)malloc(sizeof(int) * lem->room_num);
		tmp->next->next = NULL;
		tmp->next->way_len = 0;
		i = -1;
		while (++i < lem->room_num)
		{
			tmp->next->way[i] = lem->visited[i];
			if (tmp->next->way[i] != -1)
				tmp->next->way_len++;
		}
	}
}
