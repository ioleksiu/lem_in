/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_and_push_ants.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:15:25 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/16 14:15:32 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		find_ways_and_push_ants(t_lemin *lem, t_rooms *rooms)
{
	visited_arr(lem);
	queue_visit_alloc(lem);
	dfs(lem);
	if (lem->ways == NULL)
		ft_error();
	print_input(lem);
	sort_ways(lem);
	ft_remove_redundant_path(lem);
	muravei_idi(lem, rooms);
}
