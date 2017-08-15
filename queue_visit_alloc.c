/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_visit_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:16:33 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:16:35 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		queue_visit_alloc(t_lemin *lem)
{
	int	n;
	int	i;

	i = -1;
	n = lem->room_num * lem->room_num;
	lem->queue = (int *)malloc(sizeof(int) * n);
	while (++i < n)
		lem->queue[i] = -1;
	lem->visited = (int *)malloc(sizeof(int) * lem->room_num);
	lem->visited[0] = 0;
	i = 0;
	while (++i < lem->room_num)
		lem->visited[i] = -1;
}
