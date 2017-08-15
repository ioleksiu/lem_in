/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:21:59 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:22:01 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		visited_arr(t_lemin *lem)
{
	int	i;

	i = -1;
	lem->is_visited = malloc(sizeof(int) * lem->room_num);
	while (++i < lem->room_num)
		lem->is_visited[i] = 0;
	i = -1;
	lem->way = malloc(sizeof(int) * lem->room_num);
	while (++i < lem->room_num)
		lem->way[i] = -1;
}
