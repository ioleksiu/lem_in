/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_q_static.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:52:39 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 18:52:44 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_q_static(t_lemin *lem, int *ochered)
{
	int		v;
	int		i;
	int		count;

	v = last_v(lem);
	i = -1;
	count = -1;
	while (++i < lem->room_num)
		if (lem->matrix[v][i] == 1)
			ochered[++count] = i;
	while (count < lem->room_num)
		ochered[++count] = -1;
}
