/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:20:03 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:20:05 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		sort_ways(t_lemin *lem)
{
	t_ways	*tmp;

	tmp = lem->ways;
	while (tmp->next)
	{
		if (tmp->way_len > tmp->next->way_len)
		{
			swap_nodes(tmp, tmp->next);
			tmp = lem->ways;
		}
		else
			tmp = tmp->next;
	}
}
