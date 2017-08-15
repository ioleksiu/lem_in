/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:20:52 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:20:56 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swap_rooms(t_rooms *a, t_rooms *b)
{
	t_rooms	*c;

	c = malloc(sizeof(t_rooms*));
	c->r_name = a->r_name;
	c->x = a->x;
	c->y = a->y;
	a->r_name = b->r_name;
	a->x = b->x;
	a->y = b->y;
	b->r_name = c->r_name;
	b->x = c->x;
	b->y = c->y;
}
