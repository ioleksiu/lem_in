/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_visited_static.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:27:31 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:27:48 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_visited_static(int *q, t_lemin *lem)
{
	int		i;

	i = -1;
	while (++i < lem->room_num)
		if (lem->visited[i] == -1)
			break ;
	lem->visited[i] = last_q_static(q);
}
