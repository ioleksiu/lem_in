/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:20:17 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:20:19 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lemin			*struct_init(void)
{
	t_lemin		*a;

	a = malloc(sizeof(t_lemin));
	a->end_id = -1;
	a->matrix = NULL;
	a->n_ants = 0;
	a->room_num = -1;
	a->start_id = -1;
	a->is_start = 0;
	a->is_end = 0;
	a->is_link = 0;
	a->command = 0;
	a->ways = NULL;
	a->input = ft_strnew(0);
	a->way_num = 0;
	return (a);
}
