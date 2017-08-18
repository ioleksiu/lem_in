/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:04:43 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:04:45 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		dfs(t_lemin *lem)
{
	int	och[lem->room_num + 1];

	if (last_v(lem) == lem->room_num - 1)
	{
		lem->way_num++;
		add_way(lem);
		del_last_visited(lem);
		del_q_static(och, lem->room_num);
		return ;
	}
		if (lem->way_num == 2500)
			return;
	add_q_static(lem, och);
	while (och[0] != -1 && !(och[0] == 0 && och[1] == -1))
	{
		if (last_q_static(och) != -1 && !is_visited(lem, last_q_static(och)))
		{
			add_visited_static(och, lem);
			del_q_static(och, lem->room_num);
			dfs(lem);
		}
		if (is_visited(lem, last_q_static(och)))
			del_q_static(och, lem->room_num);
	}
	del_last_visited(lem);
}
