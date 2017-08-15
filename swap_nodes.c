/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:20:33 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:20:34 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swap_nodes(t_ways *a, t_ways *b)
{
	t_ways	*c;

	c = (t_ways*)malloc(sizeof(t_ways));
	c->way_len = a->way_len;
	c->way = a->way;
	a->way_len = b->way_len;
	a->way = b->way;
	b->way_len = c->way_len;
	b->way = c->way;
	free(c);
}
