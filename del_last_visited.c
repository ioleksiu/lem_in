/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_last_visited.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:57:33 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:57:38 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_last_visited(t_lemin *lem)
{
	int	i;

	i = 0;
	if (lem->visited[lem->room_num - 1] != -1)
	{
		lem->visited[lem->room_num - 1] = -1;
		return ;
	}
	while (i < lem->room_num - 1)
	{
		if (lem->visited[i + 1] == -1)
		{
			lem->visited[i] = -1;
			return ;
		}
		i++;
	}
}
