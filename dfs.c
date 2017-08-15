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
	int	ochered[lem->room_num + 1];

	if (last_v(lem) == lem->room_num - 1)
	{
		lem->way_num++;
		add_way(lem);
		del_last_visited(lem);
		del_q_static(ochered, lem->room_num);
		return ;
	}
	add_q_static(lem, ochered);
	while (ochered[0] != -1 && !(ochered[0] == 0 && ochered[1] == -1))
	{
		if (last_q_static(ochered) != -1
		&& !is_visited(lem, last_q_static(ochered)))
		{
			add_visited_static(ochered, lem);
			del_q_static(ochered, lem->room_num);
			dfs(lem);
		}
		if (is_visited(lem, last_q_static(ochered)))
			del_q_static(ochered, lem->room_num);
	}
	del_last_visited(lem);
}
